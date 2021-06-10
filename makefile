CC := g++

SRCDIR := src
BUILDDIR := build
INC := -I include
TARGET := bin/WeatherStation
TESTDIR := test/test.cpp
TEST := bin/test

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -std=c++14 -Wall -Wextra -pedantic-errors

$(TARGET): $(OBJECTS)
	@echo " Linking...";
	@echo " $(CC) $^ -o $(TARGET)"; $(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

run:
ifneq ("$(wildcard $(TARGET))", "$(TARGET)")
	@echo "Linking..."; make
endif
	@echo "Starting program"; ./${TARGET}

docs:
	@echo "Generating documentation...";
	@doxygen
	@open doxygen/html/index.html

test:
	@echo "Building testfiles...";
	@echo "$(CC) -o $(TEST) $(TESTDIR) -Icppnit";
	@echo "Starting test program"; ./${TEST}
