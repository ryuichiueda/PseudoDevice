#Reference: http://www.devdrv.co.jp/linux/kernel26-makefile.htm
TARGET:= logger.ko

all: ${TARGET}

logger.ko: logger.c
	make -C /usr/src/linux-headers-`uname -r` M=`pwd` V=1 modules

clean:
	make -C /usr/src/linux-headers-`uname -r` M=`pwd` V=1 clean

obj-m:= logger.o

clean-files := *.o *.ko *.mod.[co] *~

install: all
	sudo mknod /dev/logger c 0x0123 0
	sudo chmod 0666 /dev/logger
	sudo insmod ./logger.ko
 
uninstall:
	sudo rmmod ./logger
	sudo rm -f /dev/logger
