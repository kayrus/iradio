```
Linux version 2.6.35.4 (root@dev2.mediayou.net) (gcc version 4.2.1) #1021 PREEMPT Fri Dec 5 16:40:02 CST 2014
CPU: ARM926EJ-S [41069265] revision 5 (ARMv5TEJ), cr=00053177
CPU: VIVT data cache, VIVT instruction cache
Machine: W55FA93
Memory policy: ECC disabled, Data cache writeback
On node 0 totalpages: 8192
free_area_init_node: node 0, pgdat c03a572c, node_mem_map c03dd000
  Normal zone: 64 pages used for memmap
  Normal zone: 0 pages reserved
  Normal zone: 8128 pages, LIFO batch:0
CPU type 0x00fa5c30 is W55FA93
w55fa93_external_clock       = 12.0 MHz
w55fa93_apll_clock   = 988000 KHz
w55fa93_upll_clock   = 240000 KHz
w55fa93_system_clock = 240000 KHz
w55fa93_cpu_clock    = 240000 KHz
w55fa93_ahb_clock    = 120000 KHz
w55fa93_apb_clock    = 60000 KHz
Built 1 zonelists in Zone order, mobility grouping on.  Total pages: 8128
Kernel command line: root=/dev/ram0 console=ttyS1,115200n8 rdinit=/sbin/init mem=32M vt.global_cursor_default=0 clocksource=jiffies
PID hash table entries: 128 (order: -3, 512 bytes)
Dentry cache hash table entries: 4096 (order: 2, 16384 bytes)
Inode-cache hash table entries: 2048 (order: 1, 8192 bytes)
Memory: 32MB = 32MB total
Memory: 28504k/28504k available, 4264k reserved, 0K highmem
Virtual kernel memory layout:
    vector  : 0xffff0000 - 0xffff1000   (   4 kB)
    fixmap  : 0xfff00000 - 0xfffe0000   ( 896 kB)
    DMA     : 0xff600000 - 0xffe00000   (   8 MB)
    vmalloc : 0xc2800000 - 0xe0000000   ( 472 MB)
    lowmem  : 0xc0000000 - 0xc2000000   (  32 MB)
    modules : 0xbf000000 - 0xc0000000   (  16 MB)
      .init : 0xc0008000 - 0xc0134000   (1200 kB)
      .text : 0xc0134000 - 0xc038f000   (2412 kB)
      .data : 0xc0390000 - 0xc03a5d80   (  88 kB)
Hierarchical RCU implementation.
     RCU-based detection of stalled CPUs is disabled.
     Verbose stalled-CPUs detection is disabled.
NR_IRQS:32
Console: colour dummy device 80x30
selected clock b71b00 quot 5
console [ttyS1] enabled
Calibrating delay loop... 119.60 BogoMIPS (lpj=598016)
pid_max: default: 4096 minimum: 301
Mount-cache hash table entries: 512
CPU: Testing write buffer coherency: ok
NET: Registered protocol family 16
### Call platform_device_register in w55fa93_arch_init 
bio: create slab <bio-0> at 0
SCSI subsystem initialized
usbcore: registered new interface driver usbfs
usbcore: registered new interface driver hub
usbcore: registered new device driver usb
Advanced Linux Sound Architecture Driver Version 1.0.23.
cfg80211: Calling CRDA to update world regulatory domain
NET: Registered protocol family 2
IP route cache hash table entries: 1024 (order: 0, 4096 bytes)
TCP established hash table entries: 1024 (order: 1, 8192 bytes)
TCP bind hash table entries: 1024 (order: 0, 4096 bytes)
TCP: Hash tables configured (established 1024 bind 1024)
TCP reno registered
NET: Registered protocol family 1
register clock device
w55fa93_edma_init
JFFS2 version 2.2. (NAND) © 2001-2006 Red Hat, Inc.
msgmni has been set to 55
io scheduler noop registered (default)
---w55fa93fb_init ----w55fa93 frame buffer init!!! 
###########w55fa93 frame buffer probe############
check_var(var=c1c60020, info=c1c60000)
w55fa93 LCD driver has been installed successfully
w55fa93 Sysmgr driver has been initialized successfully!
w90x900 GPIO driver has been installed successfully.
W55FA93 uart driver has been initialized successfully!
w55fa93-uart.0: w55fa93_serial0 at MMIO 0xb8008000 (irq = 13) is a W55FA93
w55fa93-uart.1: w55fa93_serial1 at MMIO 0xb8008100 (irq = 24) is a W55FA93
dataflash_probe ++
MfcID = 0xef15 
MX25L6405D MTD (188 KBytes)
mtd: Giving out device 0 to MX25L6405D MTD
dataflash_probe status = 0 --
MfcID = 0xef15 
spi flash id = 0000ef15
W55FA93 SPI0 driver has been installed successfully!
ohci_hcd: USB 1.1 'Open' Host Controller (OHCI) Driver
ohci_hcd_w55fa93_drv_probe
usb_hcd_w55fa93_probe
get_pll
External clock = 12MHz
NF: 40, NR: 2, NO: 1
PLL is 240   ---
div1 = 1
div0 = 1
div0 = 2
div0 = 3
div0 = 4
div0 = 5
Div1 = 0,  Div0 = 4
USBH IP  Reset
CONFIG_W55FA93_USB_HOST_LIKE_PORT1
w55fa93-ohci w55fa93-ohci: Nuvoton W55FA93 OHCI Host Controller
w55fa93-ohci w55fa93-ohci: new USB bus registered, assigned bus number 1
w55fa93-ohci w55fa93-ohci: irq 18, io mem 0xb1009000
ohci_w55fa93_start
hub 1-0:1.0: USB hub found
hub 1-0:1.0: 2 ports detected
USB device plug in
ohci_hcd_w55fa93_init
CONFIG_W55FA93_USB_HOST_LIKE_PORT1
Error: Driver 'w55fa93-ohci' is already registered, aborting...
NUC930 ADC Keypad driver has been initialized successfully!
SC6122 Remote Controller driver has been initialized successfully!

i2c /dev entries driver
w55fa93-i2c w55fa93-i2c: bus frequency set to 100 KHz
w55fa93-i2c w55fa93-i2c: Add W55FA93 I2C port adapter
i2c gpio scl=(2)8, sda=(2)9
w55fa93_gpio_configure()-2,8
w55fa93_gpio_configure()-2,9
Linux video capture interface: v2.00
jpegcodec_init
Added W55FA93 MMC/SD driver (20121225)
w55fa93evb_asoc_dev = 0xc0c16da0 !!! 
asoc: W55FA93_DAC HiFi <-> w55fa93-spu mapping ok
ret = 0x0 !!!, platform device added 
ALSA device list:
  #0: W55FA93_SPU (W55FA93_DAC)
TCP cubic registered
NET: Registered protocol family 17
selected clock b71b00 quot 5
Freeing init memory: 1200K
selected clock b71b00 quot 5
selected clock b71b00 quot 5
JFFS2 flash size adjusted to 163840KiB
JFFS2 write-buffering enabled buffer (4096) erasesize (32768)
hub 1-0:1.0: unable to enumerate USB device on port 1
usb 1-1: new full speed USB device using w55fa93-ohci and address 3
rtusb init rt2870 --->
usbcore: registered new interface driver rt2870
USB device plug in
Initializing USB Mass Storage driver...
usbcore: registered new interface driver usb-storage
USB Mass Storage support registered.
0x1300 = 00064300
selected clock b71b00 quot 5
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
Set JPG Divider to 2
<<<<<<<<<<jpegcodec_mmap>>>>>>>>>>>>>>>
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
w55fa93_vol = 1
unlink cmd rsp urb
usbcore: deregistering interface driver rt2870
RtmpOSNetDevDetach(): RtmpOSNetDeviceDetach(), dev->name=ra0!
<--- rtusb exit
usbcore: deregistering interface driver usb-storage
####  jyjy Peri power down!! ####
Disable USB Transceiver
Disable SPU and ADO
Disable USB phy
USB Suspend OK !!
SYS clock = 30000
CPU clock = 30000
AHB clock = 15000
APB clock = 15000
REG_CLKDIV0 = 0x18
REG_CLKDIV4 = 0x1000100
REG_UPLLCON = 0x26
-REG_CLKDIV0 = 0x718
-REG_CLKDIV4 = 0x1000000
-REG_UPLLCON = 0x26
SYS clock = 240000
CPU clock = 240000
AHB clock = 120000
APB clock = 60000
REG_CLKDIV0 = 0x718
REG_CLKDIV4 = 0x1000000
REG_UPLLCON = 0x26
-REG_CLKDIV0 = 0x18
-REG_CLKDIV4 = 0x1000100
-REG_UPLLCON = 0x26
####  jyjy Peri power up!! ####
Enable USB Transceiver
Enable SPU and ADO
Enable USB phy
Enable TV DAC 
USB Resume OK!!
usb 1-1: USB disconnect, address 3
USB device plug out
usb 1-1: new full speed USB device using w55fa93-ohci and address 4
USB device plug in
rtusb init rt2870 --->
usbcore: registered new interface driver rt2870
0x1300 = 00064300
Initializing USB Mass Storage driver...
usbcore: registered new interface driver usb-storage
USB Mass Storage support registered.
unlink cmd rsp urb
usbcore: deregistering interface driver rt2870
RtmpOSNetDevDetach(): RtmpOSNetDeviceDetach(), dev->name=ra0!
<--- rtusb exit
usbcore: deregistering interface driver usb-storage
####  jyjy Peri power down!! ####
Disable USB Transceiver
Disable SPU and ADO
Disable USB phy
USB Suspend OK !!
SYS clock = 30000
CPU clock = 30000
AHB clock = 15000
APB clock = 15000
REG_CLKDIV0 = 0x18
REG_CLKDIV4 = 0x1000100
REG_UPLLCON = 0x26
-REG_CLKDIV0 = 0x718
-REG_CLKDIV4 = 0x1000000
-REG_UPLLCON = 0x26
SYS clock = 240000
CPU clock = 240000
AHB clock = 120000
APB clock = 60000
REG_CLKDIV0 = 0x718
REG_CLKDIV4 = 0x1000000
REG_UPLLCON = 0x26
-REG_CLKDIV0 = 0x18
-REG_CLKDIV4 = 0x1000100
-REG_UPLLCON = 0x26
####  jyjy Peri power up!! ####
Enable USB Transceiver
Enable SPU and ADO
Enable USB phy
Enable TV DAC 
USB Resume OK!!
usb 1-1: USB disconnect, address 4
USB device plug out
usb 1-1: new full speed USB device using w55fa93-ohci and address 5
USB device plug in
rtusb init rt2870 --->
usbcore: registered new interface driver rt2870
0x1300 = 00064300
Initializing USB Mass Storage driver...
usbcore: registered new interface driver usb-storage
USB Mass Storage support registered.
```
