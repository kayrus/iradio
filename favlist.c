#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define member_size(type, member) sizeof(((type *)0)->member)

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
	char title[99];
	char url[250];
	unsigned char zeros[5];
	struct item *next_item;
};

#define STRUCT_SIZE_NO_PTR 366 /* because of struct alignment next_item pointer adds not 8, but 10*/

int add_to_list(struct strings_list *list, const char *title, const char *url) {
	struct item *item;
	struct item *prv_item;

	if (title == NULL || url == NULL) {
		printf("Title or URL are null\n");
		return -2;
	}
	if ((strlen(title)+2) > member_size(struct item, title)) {
		printf("Title length is too long (%d)\n", (int)strlen(title));
		return -2;
	}
	if (strlen(url) > member_size(struct item, url)) {
		printf("URL length is too long (%d)\n", (int)strlen(url));
		return -2;
	}
	if (list->size == 0) {
		list->items = (struct item *)calloc(1,sizeof(struct item));
		if (list->items == NULL) {
			printf("Error allocating memory\n");
			return -2;
		}
		item = list->items;
	} else {
		item = list->items->next_item;
		prv_item = list->items;
		while (item != NULL) {
			prv_item = item;
			item = item->next_item;
		}
		item = (struct item *)calloc(1,sizeof(struct item));
		if (item == NULL) {
			printf("Error allocating memory\n");
			return -2;
		}
		prv_item->next_item = item;
	}

	list->size++;

	item->space = 0x20;
	item->title_len = strlen(title)+2;
	item->eighty = 0x80;
	strcpy(item->title,title);
	strcpy(item->url,url);
	item->next_item = NULL;

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
	struct item *item;

	f = fopen(filename, "wb");
	if (f != NULL) {
		fwrite(&(list->size),sizeof(list->size), 1, f);
		for( i = 0; i < list->size; i++) {
			if (i == 0) {
				item = list->items;
			} else {
				item = item->next_item;
			}
			if (item == NULL) {
				printf("End of list at %d, but size is %d. Stop the loop.\n",i,list->size);
				break;
			}
			fwrite(item, STRUCT_SIZE_NO_PTR, 1, f);
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
	char *import = "playlist.csv";
	char *export = "myradio.cfg";
	int res;
	char line[1024];
	char *tmp, *tmp1;

	FILE* input = fopen(import, "r");
	if (input != NULL) {
		while (fgets(line, 1024, input)) {
			tmp = strdup(line);
			tmp1 = strdup(line);
			if (add_to_list(radio_list, getfield(tmp, 1), getfield(tmp1, 2)) != 1) {
				printf("Failed to create binary list\n");
				free(tmp);
				free(tmp1);
				fclose(input);
				return 1;
			}
			free(tmp);
			free(tmp1);
		}
		fclose(input);
	} else {
		printf("Failed to open file '%s' for read\n",import);
		return 1;
	}

	res = save_to_file(radio_list,export);
	if (res < 0) {
		return 1;
	}
	printf("Successfully wrote '%s' binary playlist\n",export);

	return 0;
}
