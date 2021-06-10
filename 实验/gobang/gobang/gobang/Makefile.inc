#定义目标
CC = gcc
#CC = aarch64_be-linux-gnu-gcc
ifeq ($(INTERNEL_ROOT), )
	INTERNEL_ROOT = $(shell pwd)
endif

#指定目标路径
ifeq ($(BASE_BUILDDIR), )
	BASE_BUILDDIR = $(TGTROOT)/build
endif

ifneq ($(EXEC), )
	EXEC_T		=	$(BASE_BUILDDIR)/$(EXEC)
	TARGET		=	$(EXEC)
	BUILD_TARGET = 1
endif

ifeq ($(SRCS), )
	SRCS	= $(wildcard *.c)
endif
OBJS    = $(SRCS:%.c=$(OBJSDIR)/%.o)

ifneq ($(BUILD_TARGET), )
ALL_OBJS    = $(shell find $(BASE_BUILDDIR) -type f | xargs)
endif

OBJSDIR         = $(BASE_BUILDDIR)/$(subst $(TGTROOT)/,,$(INTERNEL_ROOT))

$(shell mkdir -p $(OBJSDIR))


#终极目标
.PHONY:all
all: prepare $(SUBDIRS) $(OBJS) $(EXEC_T)

prepare:
	$(shell rm -f $(EXEC_T))
	
#.o中间文件的编译
$(OBJSDIR)/%.o : %.c 
	@echo -e "    CC  => $(subst $(TGTROOT)/,,$@)"
#	@echo -e "  $(CC) -c $(CFLAGS) $< -o $@"
	@$(CC) -c $(CFLAGS) $(LDFLAGS) $< -o $@
	

#可执行程序目标的链接
$(EXEC_T): $(OBJS)
	@echo -e "    LD  => $(subst $(TGTROOT)/,,$@)"
#	@echo -e "  $(CC) $(ALL_OBJS) $(LDFLAGS) -o $@"
	@$(CC) $(ALL_OBJS) $(LDFLAGS) -o $@
	
#子目录的处理
$(SUBDIRS)::
	@echo -e "MAKE \t-C [$(subst $(TGTROOT)/,,$@)]"
	@$(MAKE) --no-print-directory -C $@ 


clean_dirs := $(addprefix _clean_, $(SUBDIRS))
$(clean_dirs):
	@echo -e "MAKE \t-C $(patsubst _clean_%, %, $(subst $(TGTROOT)/,,$@)) clean"
	@$(MAKE) --no-print-directory -C $(patsubst _clean_%, %, $@) clean

.PHONY:clean
clean: $(clean_dirs)
	$(shell rm -rf $(OBJS) $(OBJSDIR) $(EXEC_T))


