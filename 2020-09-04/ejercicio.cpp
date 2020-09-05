//ejercicio #9 pag 35 presentacion: Errors on computation
//Integrantes: Julian David Jimenez Paz, Felipe Gomez Lozada

#include <iostream>
#include <cmath> //se incluye para usar sqrt

typedef float REAL;
int main(void){
    REAL x=0.0, f, fmod;
    //se define los digitos de precision de acuerdo a la variable float
    std::cout.precision(6); std::cout.setf(std::ios::scientific);
    
    //como x va de 0 a 1 en saltos de 0.01 se hacen 101 iteraciones
    for(int n=0; n<=100; n++){
        f = 5.0-sqrt(25+x*x);             //formula original
        fmod = -(x*x)/(5.0+sqrt(25+x*x)); //formula modificada con racionalizacion
        
        std::cout << x
                  << "\t" << f
                  << "\t" << fmod
                  << "\n";
        x += 0.01;
    }
    
    return 0;
}
