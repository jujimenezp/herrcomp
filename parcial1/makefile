CXX=g++
CXXFLAGS=-std=c++17
SANITFLAGS= -fsanitize=address -fsanitize=leak -fsanitize=undefined
VALGRINDFLAGS= --tool=memcheck --track-origins=yes --leak-check=full
all:2.x

2.x: 2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

valgrind: 2.cpp
	$(CXX) $(CXXFLAGS) -g $< -o 2.x
	valgrind $(VALGRINDFLAGS) ./2.x

sanitizers: 2.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $< -o 2.x
	./2.x

clean:
	rm -rf *.x a.out *.x.*
