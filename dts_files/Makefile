obj-m += dt_probe.o

module:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

dt: testoverlay.dts
	dtc -@ -I dts -O dtb -o testoverlay.dtbo testoverlay.dts
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -rf testoverlay.dtbo