# iradio
Information about the firmware inside Internet Radio (Conrad's renkforce IR 1)

## Favorites

### Prepare source playlist

Create comma separated `playlist.csv` CSV file following the format below:

```csv
Title,URL
```

### Compile and run the binary

```sh
$ make
$ ./favlist
```

#### Compile native ARM binary

Commands below will compile native ARM binary and upload it into `/tmp` dir on internet radio device. This command requires `gcc-arm-linux-gnueabi` package (but it is recommended to use [musl cross-compilers](http://musl.codu.org/)).

```sh
$ make arm
# or using musl
# CC_ARM=~/musl/bin/arm-linux-musleabi-gcc make arm
$ ./upload favlist_arm /tmp %SRC_IP% %DST_IP%
```

Following command will upload `playlist.csv` into `/tmp` dir on internet radio device.

```sh
$ ./upload playlist.csv /tmp %SRC_IP% %DST_IP%
```

Then you can run converter directly on internet radio through telnet:

```sh
$ telnet %DST_IP%
# cd /tmp
# ./favlist_arm
```

### Upload generated playlist into device

Install `python-pyftpdlib` package to configure simple FTP server on your local PC.

And `expect` package to automate telnet routines.

Then run:

```sh
$ ./runftp
```

to run temporarily FTP server. And then:

```sh
$ ./upload myradio.cfg /flash %SRC_IP% %DST_IP%
```

to upload `myradio.cfg` from the current directory into your Internet Radio's `/flash/` directory.

#### Download file from internet radio device into the current directory

```sh
$ ./download %remote_full_path% %SRC_IP% %DST_IP%
```

### myradio.cfg binary format

```
Amount of entries: 2b
Every entry len: 366b
  0x00: 1b
  0x00|0x02|0x03: 1b
  0x20 (32): 1b
  0x00: 6b
  0x07|0x05: 1b
  len(0xTITLE+1): 1b
  0x80: 1b
  0xTITLE: 40b
  0x00: 59b
  0xURL: 250b
  0x00: 5b
0x00: 2b
```

#### Original file

[`myradio.cfg.orig`](myradio.cfg.orig)

#### Dump HEX in more user friendly format

```sh
$ xxd -c 183 myradio.cfg.orig
```

## Telnet

```sh
$ telnet %iradio_ip%

Entering character mode
Escape character is '^]'.


(none) login: root
Password: password


BusyBox v1.15.2 (2014-05-05 11:57:25 CST) built-in shell (ash)
Enter 'help' for a list of built-in commands.

# 
```

### Info

```sh
# cat /proc/cpuinfo
Processor       : ARM926EJ-S rev 5 (v5l)
BogoMIPS        : 119.60
Features        : swp half thumb fastmult edsp java 
CPU implementer : 0x41
CPU architecture: 5TEJ
CPU variant     : 0x0
CPU part        : 0x926
CPU revision    : 5

Hardware        : W55FA93
Revision        : 0000
Serial          : 0000000000000000
# free
              total         used         free       shared      buffers
  Mem:        29704        21040         8664            0            0
 Swap:            0            0            0
Total:        29704        21040         8664
# ps -www
  PID USER       VSZ STAT COMMAND
    1 root       432 S    init       
    2 root         0 SW   [kthreadd]
    3 root         0 SW   [ksoftirqd/0]
    4 root         0 SW   [watchdog/0]
    5 root         0 SW   [events/0]
    6 root         0 SW   [khelper]
    9 root         0 SW   [async/mgr]
  108 root         0 SW   [sync_supers]
  110 root         0 SW   [bdi-default]
  111 root         0 SW   [kblockd/0]
  120 root         0 SW   [khubd]
  123 root         0 SW   [kmmcd]
  133 root         0 SW   [cfg80211]
  221 root         0 SW   [kswapd0]
  253 root         0 SW   [sdioeventd]
  274 root         0 SWN  [jffs2_gcd_mtd0]
  292 root       432 S    httpd -p 8080 -h /UIData 
  294 root       440 S    telnetd -l /bin/login 
  295 root       292 S    ./init_process OSDDAEMON W950OSD 
  298 root      7500 R    W950OSD 3 4 
  301 root      7500 S    W950OSD 3 4 
  302 root      7500 S    W950OSD 3 4 
  303 root      7500 S    W950OSD 3 4 
  304 root       292 S    ./init_process OSDDAEMON UIProto 
  306 root      3408 S    UIProto 3 Param2 
  313 root      3408 S    UIProto 3 Param2 
  314 root      3408 S    UIProto 3 Param2 
  315 root      3408 S    UIProto 3 Param2 
  316 root      3408 S    UIProto 3 Param2 
  317 root      3408 S    UIProto 3 Param2 
  319 root      3408 S    UIProto 3 Param2 
  320 root      3408 S    UIProto 3 Param2 
  321 root      3408 S    UIProto 3 Param2 
  322 root      3408 S    UIProto 3 Param2 
  324 root      3408 S    UIProto 3 Param2 
  327 root      3408 S    UIProto 3 Param2 
  328 root      3408 S    UIProto 3 Param2 
  330 root      3408 S    UIProto 3 Param2 
  333 root      3408 S    UIProto 3 Param2 
  334 root      3408 S    UIProto 3 Param2 
  370 root       292 S    ./init_process OSDDAEMON mplayer 
  373 root       432 S    init       
  374 root       432 S    init       
  375 root       432 S    init       
  376 root       432 S    init       
  378 root      2036 S    mplayer 0 Param2 
  384 root      2036 S    mplayer 0 Param2 
  390 root      2036 S    mplayer 0 Param2 
  429 root      3408 S    UIProto 3 Param2 
  430 root      3408 S    UIProto 3 Param2 
 1302 root       444 S    -sh 
 2119 root         0 SW   [flush-mtd-unmap]
 2127 root         0 SW   [RtmpTimerTask]
 2128 root         0 SW   [RtmpMlmeTask]
 2129 root         0 SW   [RtmpCmdQTask]
 2130 root         0 SW   [RtmpWscTask]
 2183 root       432 S    udhcpc -i ra0 -p /tmp/udhcpc-ra0.pid 
 2219 root      2036 S    mplayer 0 Param2 
 2220 root      2036 S    mplayer 0 Param2 
 2245 root       444 S    -sh 
 2426 root       436 R    ps -www 
# ls -la /flash
drwxr-xr-x    3         0 Jan  1  1970 .
drwxr-xr-x   16         0 Jan  1  1970 ..
-rwxr-xr-x    1       389 Jan  1  2015 IRMap.cfg
-rwxr-xr-x    1       153 Jan  1  2015 KeyPadMap.cfg
-rw-r--r--    1        40 Jan  1  2015 fmno.dat
-rw-r--r--    1       661 Jul  9 22:12 iradio.cfg
-rw-r--r--    1      2932 Jul  9 21:01 myradio.cfg
-rwxr-xr-x    1      1132 Jan  1  2015 product.cfg
-rw-r--r--    1      4036 Jul  9 22:12 recnt_radio.cfg
-rw-r--r--    1         9 May  5 08:57 timeset.cfg
-rw-r--r--    1       188 Jul  9 22:12 uiparam
-rw-r--r--    1       106 Jul  9 22:12 wifi.cfg
# cat /usr/Kernel.txt 
20141007_M7_TFT_7601_Kernel
# cat /proc/version
Linux version 2.6.35.4 (root@dev2.mediayou.net) (gcc version 4.2.1) #1021 PREEMPT Fri Dec 5 16:40:02 CST 2014
# cat /proc/cmdline 
root=/dev/ram0 console=ttyS1,115200n8 rdinit=/sbin/init mem=32M vt.global_cursor_default=0 clocksource=jiffies
# cat /proc/mtd
dev:    size   erasesize  name
mtd0: 0002f000 00001000 "MX25L6405D MTD"
# mount
rootfs on / type rootfs (rw)
none on /proc type proc (rw,relatime)
/dev/mtdblock0 on /flash type jffs2 (rw,relatime)
none on /sys type sysfs (rw,relatime)
none on /dev/pts type devpts (rw,relatime,mode=600)
```

## UIProto

```sh
$ strings UIProto | grep 'UIProto Version'
UIProto Version 3.50 2014/12/04
```

[`strings UIProto` output](UIProto_strings.md)

## [dmesg output](dmesg.md)

## Renkforce IR 1 board

![Renkforce IR1](renkforce_ir1.jpg)
