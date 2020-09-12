//generacion de numeros aleatorios
#include <iostream>
#include <random>

int main(void){
    const int N = 10000;
    const int NBINS = 20;
    const double XMIN = 0.0, XMAX = 1.0;
    const int SEED = 1;
    const double DXHISTO = (XMAX - XMIN)/NBINS;
    
    double histo[NBINS] = {0.0};

    std::mt19937 gen(SEED); //declarando el generador
    std::uniform_real_distribution<double> dis(XMIN, XMAX);

    for(int ii = 0; ii < N; ii++){
        double r = dis(gen);
        int bin = int((r - XMIN)/DXHISTO);
        histo[bin] += 1;
    }

    for(int ii = 0; ii < NBINS; ++ii){
        std::cout << XMIN + ii*DXHISTO << "\t" << histo[ii] << "\n";
    }
    
    return 0;
}
