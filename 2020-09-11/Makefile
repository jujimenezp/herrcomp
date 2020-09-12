#makefile Legendre y Random

all : legendre_grafica datos_random.txt

%.x : %.cpp
	g++ -std=c++17 $< -o $@

datos.txt : legendre.x
	./legendre.x > $@

datos_random.txt : random.x
	./random.x > $@

legendre_grafica : datos.txt plot_legendre_script
	gnuplot -p plot_legendre_script

clean :
	rm legendre.x random.x datos.txt datos_random.txt
