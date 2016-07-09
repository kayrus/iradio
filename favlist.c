#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct strings_list {
	unsigned short size;
	struct item *items;
	unsigned short end;
};

struct item {
	unsigned char zero;
	unsigned char flag1;
	unsigned char space;
	unsigned char six_bytes[6];
	unsigned char flag2;
	unsigned char title_len;
	unsigned char eighty;
	unsigned char title[99];
	unsigned char url[250];
	unsigned char zeros[5];
};

int add_to_list(struct strings_list *list, const char *title, const char *url) {
	struct item *tmp_list;

	if (list->size == 0) {
		list->items = (struct item *)malloc(sizeof(struct item));
		if (list->items == NULL) {
			printf("Error allocating memory\n");
			return -2;
		}
	} else {
		tmp_list = (struct item *)realloc(list->items,sizeof(struct item)*(list->size+1));
		if (tmp_list == NULL) {
			printf("Error reallocating memory\n");
			return -2;
		}
		list->items = tmp_list;
	}

	list->size++;

	list->items[list->size-1].space = 0x20;
	list->items[list->size-1].title_len = strlen(title)+2;
	list->items[list->size-1].eighty = 0x80;
	strcpy(list->items[list->size-1].title,title);
	strcpy(list->items[list->size-1].url,url);

	return 1;
}

const char* getfield(char* line, int num) {
	const char* tok;

	for (tok = strtok(line, ","); tok && *tok; tok = strtok(NULL, ",\n")) {
		if (!--num)
			return tok;
	}

	return NULL;
}

int save_to_file(struct strings_list *list, char *filename) {
	FILE *f;
	unsigned short i;

	f = fopen(filename, "wb");
	if (f != NULL) {
		fwrite(&(list->size),sizeof(list->size), 1, f);
		for( i = 0; i < list->size; i++) {
			fwrite(&(list->items[i]), sizeof(struct item), 1, f);
		}
		fwrite(&(list->end),sizeof(list->end), 1, f);
		fclose(f);
		return 0;
	} else {
		printf("Failed to open file '%s' for write\n",filename);
		return -1;
	}
}

int main() {
	struct strings_list *radio_list=malloc(sizeof(struct strings_list));
	char *filename = "myradio.cfg";
	int res;

	FILE* input = fopen("playlist.csv", "r");
	char line[1024];
	while (fgets(line, 1024, input)) {
		char* tmp = strdup(line);
		add_to_list(radio_list, getfield(tmp, 1), getfield(tmp, 2));
		free(tmp);
	}
	fclose(input);

	res = save_to_file(radio_list,filename);
	if (res < 0) {
		return 1;
	}

	return 0;
}
