
PROGRAMS_SRC=$(wildcard *.cc)
PROGRAMS=$(patsubst %.cc,%,$(PROGRAMS_SRC))

SOURCES=$(wildcard ../src/*.cc)
OBJECTS=$(patsubst %.cc,%.o,$(SOURCES))

CXXFLAGS := -I../include

PHONY := all

all: $(PROGRAMS)
#	$(V)$(CXX) -o $@ $^

$(PROGRAMS): LDLIBS += $(OBJECTS)

ifeq (@, $(V))
%.o: %.cc
	@$(CXX) -c $< $(CXXFLAGS)
	@echo Compile -  $<
else
%.o: %.cc
	$(CXX) -c $< $(CXXFLAGS)
endif

clean:
	rm -rf *.o
