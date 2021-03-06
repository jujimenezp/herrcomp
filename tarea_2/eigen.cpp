//Tiempo para calcular eigenvalores y eigenvectores
//Integrantes:
//Julian David Jimenez Paz
//Felipe Gomez Lozada
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <chrono>

double solve(int n);

int main(int argc,char **argv)
{
    std::cout.precision(15);
    
    double t=0.0;
    int  N = std::atoi(argv[1]);

    for(int i=0; i<2; ++i){
    t += solve(N);
    }

    std::cout << t/2.0 << std::endl;

    return 0;
}

double solve(int n){
    Eigen::MatrixXd A(n, n);
    A = Eigen::MatrixXd::Random (n,n);

    auto start = std::chrono::steady_clock::now();
    Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigensolver(A);
    auto end = std::chrono::steady_clock::now();
    double time = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()*1.0e-9;
    
    if (eigensolver.info() != Eigen::Success) abort();
   
    return time;
}
