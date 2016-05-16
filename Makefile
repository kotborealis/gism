CC := clang++
SRCDIR :=./src
BUILDDIR := ./build
TARGET := ./bin/ism

SRCEXT := cc
SOURCES := $(shell find $(SRCDIR) -type f -name '*.$(SRCEXT)')
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS :=  -g -std=c++11
CFLAGS += -Ofast -march=native
INC := -I$(SRCDIR)

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	$(CC) $^ -o $(TARGET) $(LIB) $(CFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)/$(LIBDIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@$(RM) -r $(BUILDDIR)/*.o $(TARGET)

test: $(TARGET)
	@echo " Testing..."
	node ./tools/test.js ./bin/ism ./tests/
.PHONY: clean
