CFLAGS=-g -O0 -Wall -Wextra -Isrc -rdynamic $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCES_DIR=src
INCLUDES_DIR=includes

# Data structures
SOURCES+=$(SOURCES_DIR)/bistree.c
SOURCES+=$(SOURCES_DIR)/bitree.c
SOURCES+=$(SOURCES_DIR)/chtbl.c
SOURCES+=$(SOURCES_DIR)/clist.c
SOURCES+=$(SOURCES_DIR)/dlist.c
SOURCES+=$(SOURCES_DIR)/graph.c
SOURCES+=$(SOURCES_DIR)/heap.c
SOURCES+=$(SOURCES_DIR)/list.c
SOURCES+=$(SOURCES_DIR)/ohtbl.c
SOURCES+=$(SOURCES_DIR)/set.c
SOURCES+=$(SOURCES_DIR)/stack.c
SOURCES+=$(SOURCES_DIR)/mgsort.c
SOURCES+=$(SOURCES_DIR)/ctsort.c

# Algorithms
SOURCES+=$(SOURCES_DIR)/issort.c
SOURCES+=$(SOURCES_DIR)/qksort.c

OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

CFLAGS+=-I$(INCLUDES_DIR)

TARGET=build/libds.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# The Target Build
all: $(TARGET) $(SO_TARGET)

dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra -I$(INCLUDES_DIR) $(OPTFLAGS)
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
