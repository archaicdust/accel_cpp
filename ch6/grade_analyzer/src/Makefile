
SOURCES=$(wildcard *.cc)
OBJECTS=$(patsubst %.cc,%.o,$(SOURCES))

CXXFLAGS := -I../include

PHONY := ../grade_hw_module

all: ../grade_hw_module

#../grade_hw_module: grade_hw_module.o grade.o median.o Student_info.o
../grade_hw_module: $(OBJECTS)
	$(V)$(CXX) -o $@ $^

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
