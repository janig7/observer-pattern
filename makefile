CC := g++

SRCDIR := src
BUILDDIR := build
INC := -I include
INCT := -I./ -I src -I include -I/opt/gtest/include
TARGET := bin/WeatherStation
DOCS:= docs

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -std=c++0x -Wall -Wextra -pedantic-errors
CXXFLAGS := -std=c++0x -g -L/opt/gtest/lib -lgtest -lgtest_main -lpthread
TESTOBJ := tests/MAIN_TEST.o src/client.o src/weatherstation.o

$(TARGET): $(OBJECTS)
	@echo " Linking...";
	@echo " $(CC) $^ -o $(TARGET)"; $(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET) $(TEST)"; $(RM) -r $(BUILDDIR) $(TARGET) $(TEST) $(DOCS)/html $(DOCS)/latex

run:
ifneq ("$(wildcard $(TARGET))", "$(TARGET)")
	@echo " Linking..."; make
endif
	@echo " Starting program"; ./${TARGET}

.PHONY: docs
docs:
	@echo " Generating documentation...";
	@doxygen $(DOCS)/Doxyfile
	@open $(DOCS)/html/md__r_e_a_d_m_e.html

test: $(TESTOBJ)
	$(CC) $(CXXFLAGS) $(INCT) -o bin/TEST tests/MAIN_TEST.cpp $(TESTOBJ)
	./bin/TEST
#	@RM src/*.o tests/*.o bin/TEST

%.o: %.$(SRCEXT)
	$(CC) $(CXXFLAGS) -c $< -o $@ $(INCT)
#delete later
rm:
	@RM src/*.o tests/*.o
