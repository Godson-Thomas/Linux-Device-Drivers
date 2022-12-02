# Device-Drivers
--------
## Loading a module to kernel
```
sudo insmod hello.ko
```
## Unloading a module from kernel

```
sudo rmmod hello.ko
```

## Getting module information

```
modinfo hello_world.ko
```

## Looking into Kernel Symbol Table

```
nm hello.ko
```


<img src="https://github.com/Godson-Thomas/Linux-Device-Drivers/blob/master/Images/kernel_symbol_table.png" width="400">  <br><br>


## Checking the linux drivers
```
ls /lib/modules/$(uname -r)/kernel/drivers
```
## Kernel Symbol Table of Linux (Ubuntu)

```
cat /proc/kallsyms
```
## Checking device drivers in the system

```
cat /proc/devices
```
## Block digram of device driver types

<img src="https://github.com/Godson-Thomas/Linux-Device-Drivers/blob/master/Images/block_driver_types.png" width="400">  <br><br>


## Finding the dts file in the loaded kernel.

Note: Each node is a directory & each property is a file.

```
ls -l /sys/firmware/devicetree/base
```
---------------------------------------------

## Listing the modules loaded into kernel

```
lsmod
```
<img src="https://github.com/Godson-Thomas/Linux-Device-Drivers/blob/master/Images/lsmod.png" width="700">  <br><br>


## Listing the registered devices in kernel

```
cat /proc/devices
```

<img src="https://github.com/Godson-Thomas/Linux-Device-Drivers/blob/master/Images/cat_proc_devices.png" width="400">  <br><br>

## Creating a node in /dev directory for the device registered with the kernel.

```
sudo mknod /dev/gdsn c 60 0
```
c : Character device <br>
60 : Major Number <br>
0 : Minor Number <br>

<img src="https://github.com/Godson-Thomas/Linux-Device-Drivers/blob/master/Images/_dev.png" width="700">  <br><br>

