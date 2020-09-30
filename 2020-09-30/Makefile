
all: ejemplo1.x

test: test_factorial.x test_catch2.x test_googletest.x

%.o: %.cpp
	g++ -c $<

ejemplo1.x: ejemplo1.o factorial.o
	g++ $^ -o $@

test_factorial.x: test_factorial.o factorial.o
	g++ $^ -o $@

test_catch2.x: test_catch2.o factorial.o
	g++ $^ -o $@

test_googletest.x: test_googletest.o factorial.o
	g++ $^ -o $@ -lgtest

clean:
	rm -f *.x *.o a.out
