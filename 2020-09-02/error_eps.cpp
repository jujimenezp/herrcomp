//error de precision (epsilon)

#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
  std::cout.precision(15);
  std::cout.setf(std::ios::scientific);
  int N=std::atoi(argv[1]);

  float eps=1.0;
  float one=1.0;

  for(int ii=0;ii<N;ii++){
    eps=eps/2.0;
    one=1.0+eps;
    std::cout<<ii
	     <<"\t"<<one
	     <<"\t"<<eps
	     <<"\n";
  }
  return 0;
}
