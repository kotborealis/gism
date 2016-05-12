CC := g++
SRCDIR :=./
BUILDDIR := ./
LIBDIR := ./
TARGET := ./ism

SRCEXT := cc
SOURCES := $(shell find $(SRCDIR) -type f -name '*.$(SRCEXT)')
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS :=  -g -std=c++11
CFLAGS += -Ofast -floop-parallelize-all -ftree-loop-if-convert -ftree-parallelize-loops=4 -march=native
LIB :=
INC := -I$(SRCDIR) -I$(SRCDIR)/$(LIBDIR)

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB) $(CFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)/$(LIBDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR)/*.o $(TARGET)"; $(RM) -r $(BUILDDIR)/*.o $(TARGET)
.PHONY: clean
