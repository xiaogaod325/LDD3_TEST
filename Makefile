# Comment/uncomment the following line to disable/enable debugging
#DEBUG = y


# Add your debugging flag (or not) to EXTRA_FLAGS
ifeq ($(DEBUG),y)
  DEBFLAGS = -O -g -DSCULL_DEBUG # "-O" is needed to expand inlines
else
  DEBFLAGS = -O2
endif

EXTRA_FLAGS += $(DEBFLAGS)
EXTRA_FLAGS += -I$(LDDINC)

ifneq ($(KERNELRELEASE),)
# call from kernel build system

#scull-objs := main.o pipe.o access.o

#obj-m	:= scull.o
#jz_keypad-objs := jz_keypad.o 

obj-m	:= scull.o

else

KERNELDIR ?= /usr/src/linux-headers-3.2.0-29-generic-pae/


#KVER ?= $(shell uname -r)


PWD       := $(shell pwd)

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) LDDINC=$(PWD)/../include modules

endif



clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions

depend .depend dep:
	$(CC) $(EXTRA_FLAGS) -M *.c > .depend


ifeq (.depend,$(wildcard .depend))
include .depend
endif


relay_test:  relay_test.c
	arm-fsl-linux-gnueabi-gcc -o $@ $^
