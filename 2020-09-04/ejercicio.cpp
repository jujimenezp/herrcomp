//ejercicio #9 pag 35 presentacion: Errors on computation
//Integrantes: Julian David Jimenez Paz, Felipe Gomez Lozada

#include <iostream>
#include <cmath> //se incluye para usar sqrt

typedef float REAL;
REAL funcion(REAL x); //formula original
REAL funcionmod(REAL x); //formula moodificada con racionalizacion

int main(void){
  REAL x=0.0, f, fmod;
  int N=0;
    //se define los digitos de precision de acuerdo a la variable float
    std::cout.precision(8); std::cout.setf(std::ios::scientific);
    
    //como x va de 0 a 1 en saltos de 0.01 se hacen 101 iteraciones
    for(int n=0; n<=100; n++){
      f = funcion(x);
      fmod = funcionmod(x);
        
        std::cout << x
                  << "\t" << f
                  << "\t" << fmod
                  << "\n";
        N += 1;          //entero auxiliar para mejorar la precision de x
        x =(N*1.0)/100;  //x es mas exacto con esta formula que con +=0.01;
    }
    return 0;
}

REAL funcion(REAL x){
  REAL f;
  f=5.0-sqrt(25.0+x*x);
  return f;
}

REAL funcionmod(REAL x){
  REAL fmod;
  fmod=-(x*x)/(5.0+sqrt(25.0+x*x));
  return fmod;
}
