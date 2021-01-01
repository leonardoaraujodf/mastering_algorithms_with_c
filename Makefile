CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
INCLUDES=includes/

CFLAGS+=-I$(INCLUDES)

TARGET=build/libds.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# The Target Build
all: $(TARGET) $(SO_TARGET)

dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra -I$(INCLUDES) $(OPTFLAGS)
dev: all

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

build:
	mkdir -p build
	mkdir -p bin

# The Cleaner
clean:
	rm -rf build bin $(OBJECTS) $(TESTS)
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`
