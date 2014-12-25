

PROGRAMS_SRC=$(wildcard bin/*.cc)
PROGRAMS=$(patsubst %.cc,%,$(PROGRAMS_SRC))

CXXFLAGS=-g -O2 -Wall -Wextra -Iinclude -rdynamic -DNDEBUG $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCES=$(wildcard src/*.cc)
OBJECTS=$(patsubst %.cc,%.o,$(SOURCES))

TARGET=build/liburl_finder.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# The Target Build
all: $(TARGET) $(SO_TARGET) $(PROGRAMS)

dev: CXXFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all

$(TARGET): CXXFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CXX) -shared -o $@ $(OBJECTS)

$(PROGRAMS): LDLIBS += $(TARGET)

build:
	@mkdir -p build
	@mkdir -p bin

# The Cleaner
clean:
	rm -rf build $(OBJECTS)
	rm -rf $(PROGRAMS)
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`

