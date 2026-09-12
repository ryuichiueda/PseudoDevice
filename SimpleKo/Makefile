#Reference: http://www.devdrv.co.jp/linux/kernel26-makefile.htm
TARGET:= simple_ko.ko

all: ${TARGET}

simple_ko.ko: simple_ko.c
	make -C /usr/src/linux-headers-`uname -r` M=`pwd` V=1 modules

clean:
	make -C /usr/src/linux-headers-`uname -r` M=`pwd` V=1 clean

obj-m:= simple_ko.o

clean-files := *.o *.ko *.mod.[co] *~

install: all
	sudo mknod /dev/simple_ko c 0x0123 0
	sudo chmod 0666 /dev/simple_ko
	sudo insmod ./simple_ko.ko
 
uninstall:
	sudo rmmod ./simple_ko
	sudo rm -f /dev/simple_ko
