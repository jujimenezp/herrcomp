#include <iostream>
#include <cmath>
#include <cstdlib>

double sumup(int N);
double sumdown(int N);

int main(int argc, char **argv)
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    const double exact = M_PI*M_PI/6.0;
    const int NMAX = std::atoi(argv[1]);
    double df = std::fabs(sumup(NMAX) - exact)/exact;
    double dg = std::fabs(sumdown(NMAX) - exact)/exact;
    std::cout << df << "\t" << dg << std::endl;

    return 0;
}

double sumup(int N){
    double sum=0.0;
    for(int ii=1; ii<=N; ++ii){
        sum += 1/(1.0*ii*ii);
    }
    return sum;
}

double sumdown(int N){
    double sumd=0.0;
    for(int ii=N; ii>=1; --ii){
        sumd += 1/(1.0*ii*ii);
    }
    return sumd;
}

