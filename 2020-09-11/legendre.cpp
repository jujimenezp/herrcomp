//Funcion de Legendre de la libreria Standard en C++
#include <iostream>
#include <cmath>

typedef double REAL;

int main(void){
    REAL x=-1.0;
    int n=5;

    std::cout.precision(15);std::cout.setf(std::ios::scientific);
    for(int ii=0; ii<=100; ++ii){
        std::cout << ii << "\t"
                  << x << "\t"
                  <<  std::legendre(n, x)
                  << "\n";
        x += 0.02;
    }
    
    return 0;
}
