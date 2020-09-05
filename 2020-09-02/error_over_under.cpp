//analizar errores overflow y underflow

#include <iostream>
#include <cstdlib>

int main(int argc, char **argv){
  //argc cuenta el numero de argumentos en la linea de comandos
  //argv guarda los valores de esos argumentos
  std::cout.precision(15);
  std::cout.setf(std::ios::scientific);
  double under=1.0, over=1.0;
  int N=std::atoi(argv[1]);
  for(int ii=0; ii<=N; ii++){
    under /=2.0;
    over *=2.0;
    std::cout << ii
	      << "\t"<<under
	      <<"\t"<<over
	      <<"\n";
  }
  return 0;
}
