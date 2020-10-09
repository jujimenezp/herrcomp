CXX=g++
CXXFLAGS=-g -std=c++17 -fconcepts
GPROFFLAGS=-pg
CACHEGRIND_FLAGS=
CALLGRIND-FLAGS=

all: example2.x

%.x: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

gprof: example2.cpp example2.x
	$(CXX) $(CXXFLAGS) $(GPROFFLAGS)  $< -o example2.x
	./example2.x 4000 4000
	gprof ./example2.x > gprof_report.txt

callgrind: example2.x example2.cpp
	valgrind --tool=callgrind ./$< 4000 4000
	callgrind_annotate --auto=yes $$(ls -t callgrind.out.* | head -n 1) > callgrind_report.txt

cachegrind: example2.x example2.cpp
	valgrind --tool=cachegrind ./$< 4000 4000
	cg_annotate $$(ls -t cachegrind.out.* | head -n 1) > cachegrind_report.txt

clean:
	rm -f *.x *.out*
