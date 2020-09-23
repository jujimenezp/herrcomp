#Tarea de practica

N_1=40000 #Valor de N para 1.cpp
N_2=53 #valor de N para 2.cpp
X=4.2 #valor de x para 2.cpp

all : ejercicio_1 ejercicio_2

%.x : %.cpp
	g++ $< -o $@

ejercicio_1 : 1.x #Precision de maquina y numero PI
	./1.x $(N_1)

ejercicio_2 : 2.x #Calculo de arctan(x) con algoritmo y comparacion
	./2.x $(N_2) $(X)

clean :
	rm *.x
