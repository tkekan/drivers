# kbuild part of makefile
obj-m  := key.o
KDIR ?= /usr/src/linux-headers-`uname -r`

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm -fr *.o *.ko *.mod *.order *.symvers
