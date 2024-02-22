CC        = gcc
MODE     ?= DEBUG
CFLAGS   ?= -Wall -Wextra -Wpedantic -std=c99

ifeq ($(MODE), RELEASE)
CFLAGS += -O2 -mwindows -s
export RAYLIB_BUILD_MODE=RELEASE
else
CFLAGS += -ggdb
export RAYLIB_BUILD_MODE=DEBUG
endif

INCLUDES  = -I./raylib/src
LIBS      = -L./raylib/src -lraylib -lopengl32 -lgdi32 -lwinmm -lpthread
CFLAGS   += $(INCLUDES) $(LIBS)

all: depth physics

physics: physics.c raylib
	$(CC) -o physics physics.c $(CFLAGS)

depth: depth.c raylib
	$(CC) -o depth depth.c $(CFLAGS)

export PLATFORM=PLATFORM_DESKTOP
export RAYLIB_LIBTYPE=STATIC
raylib:
	$(MAKE) -C raylib/src