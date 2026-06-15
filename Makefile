CC ?= gcc
PKG_CONFIG ?= pkg-config
CFLAGS ?= $(shell $(PKG_CONFIG) --cflags raylib)
LDFLAGS ?= $(shell $(PKG_CONFIG) --libs raylib)

all: step5

step5: step5_color_draw.c
	$(CC) $(CFLAGS) step5_color_draw.c -o step5 $(LDFLAGS) -lm

clean:
	rm -f step5
