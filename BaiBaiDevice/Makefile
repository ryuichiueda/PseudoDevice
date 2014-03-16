#Reference: http://www.devdrv.co.jp/linux/kernel26-makefile.htm
TARGET:= baibai.ko

all: ${TARGET}

baibai.ko: baibai.c
	make -C /usr/src/linux-headers-`uname -r` M=`pwd` V=1 modules

clean:
	make -C /usr/src/linux-headers-`uname -r` M=`pwd` V=1 clean

obj-m:= baibai.o

clean-files := *.o *.ko *.mod.[co] *~

install: all
	sudo mknod /dev/baibai c 0x0123 0
	sudo chmod 0666 /dev/baibai
	sudo insmod ./baibai.ko
 
uninstall:
	sudo rmmod ./baibai
	sudo rm -f /dev/baibai
