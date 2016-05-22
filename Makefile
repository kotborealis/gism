CC = g++
SRCDIR =./src
BUILDDIR = ./build
TARGET = ./bin/ism

SRCEXT = cc
SOURCES = $(shell find $(SRCDIR) -type f -name '*.$(SRCEXT)')
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS =  -std=c++11 -Wall
CFLAGS += -O2 -march=native
CFLAGS += -floop-parallelize-all  -ftree-loop-if-convert -ftree-parallelize-loops=4
INC = -I$(SRCDIR)

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	$(CC) $^ -o $(TARGET) $(LIB) $(CFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo " Building..."
	@mkdir -p $(BUILDDIR)/$(LIBDIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@$(RM) -r $(BUILDDIR)/*.o $(TARGET)

test: $(TARGET)
	@echo " Testing..."
	node ./tools/test.js ./bin/ism ./tests/
.PHONY: clean
