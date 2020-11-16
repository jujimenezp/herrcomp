//Compute the integral of x^2

#include <iostream>
#include <chrono>
#include <omp.h>

void print_elapsed(auto start, auto end);
double integral(int N, double delta, int NTH);

int main(int argc, char **argv){
    const int NTH = std::atoi(argv[1]);
    
    int N = 1000000;
    double I=0.0;
    double delta = 10.0/N;

    auto start = std::chrono::steady_clock::now();
    I = integral(N, delta, NTH);
    auto end = std::chrono::steady_clock::now();
    
    print_elapsed(start, end);
    std::cout << I << "\n";

    return 0;
}

void print_elapsed(auto start, auto end){
    std::cout.precision(6); std::cout.setf(std::ios::scientific);
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()/1000.0 << "\n";
}

double integral(int N, double delta, int NTH){
    double In = 0.0, x = 0.0;
#pragma omp parallel for num_threads (NTH)
    for(int ii = 0; ii <= N; ++ii){
        x = ii*delta;
        In += x*x*delta;
    }
    
    return In;
}
