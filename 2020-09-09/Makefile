# $< -> Primera dependencia
# $^ -> Todas las dependencias
# $@ -> El nombre del target

CXX=g++
CXXFLAGS=-fsanitize=address -fsanitize=undefined

all : series_resta.x datos.txt series_resta.pdf

series_resta.x : series_resta.cpp sum.cpp
	$(CXX) $(CXXFLAGS)  $^ -o $@

datos.txt : series_resta.x
	./series_resta.x > datos.txt

series_resta.pdf : datos.txt plotfigure.gp
	gnuplot plotfigure.gp

clean:
	rm -f datos.txt series_resta.x a.out series_resta.pdf
