#定义目标

EXEC = gobang

ifeq ($(TGTROOT), )
	TGTROOT	= $(shell pwd)
endif
export TGTROOT

MAKEFILE.INC  = $(TGTROOT)/Makefile.inc
export MAKEFILE.INC 

LDFLAGS += -g -Wall -o0
CFLAGS	+= -I $(TGTROOT)/include

.PHONY: $(SUBDIRS)
SUBDIRS += 

#包含Makefile.inc
include $(MAKEFILE.INC)
