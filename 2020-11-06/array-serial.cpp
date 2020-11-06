#include <iostream>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <omp.h>

void print_elapsed(auto start, auto end, int NTH );
void fill(double * d, int n, int nth);

int main(int argc, char **argv)
{
  const int N = std::atoi(argv[1]);
  const int NTH = std::atoi(argv[2]);
  double * data = new double [N]; 

  auto start = std::chrono::steady_clock::now();
  // fill the array
  fill (data, N, NTH);
  auto end = std::chrono::steady_clock::now();
  print_elapsed(start, end, NTH);
  
  // print
  //std::cout << data[N/2] << std::endl;
  
  delete [] data;
  return 0;
}

void fill(double * d, int n, int nthreads){
  #pragma omp parallel num_threads (nthreads)
  {
    int nth = omp_get_num_threads();
    int tid = omp_get_thread_num();
    int SL = n/nth;
    
    for (int ii = tid*SL; ii < tid*SL + SL; ++ii) {
      d[ii] = 2*std::sin(ii) + std::log(ii + 1);
    }
  }

}

void print_elapsed(auto start, auto end, int NTH )
{
  std::cout.precision(6); std::cout.setf(std::ios::scientific);
  std::cout << NTH << "\t"
            << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << "\n";
}
