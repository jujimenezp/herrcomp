//error en la resto de numeros cercanos
#include <iostream>
#include <cmath>

typedef float REAL;

REAL sum1(int N);
REAL sum2(int N);
REAL sum3(int N);

int main(void)
{
    for(int N = 2; N <= 1000; N += 5)
    {
        double suma3= sum3(N);
        double delta1= std::fabs((sum1(N) - suma3)/suma3);
        double delta2 = std::fabs((sum2(N) - suma3)/suma3);
        std::cout << N << "\t" << delta1 << "\t" << delta2 << "\n";
    }

    return 0;
}

REAL sum1(int N)
{
    REAL sum=0;
    int sign=-1;
    for (int n=1;n<=2*N;n++)
    {
        sum += sign*1.0*n/(n+1);
        sign *= -1;
    }
    return sum;
}

REAL sum2(int N)
{
    REAL suma1 = 0, suma2 = 0;
    for (int n = 1; n <= N; n++){
        suma1 += (2.0*n-1)/(2*n);
        suma2 += 2.0*n/(2*n+1);
    }
    return suma2 - suma1;
}

REAL sum3(int N)
{
    REAL sum=0;
    for (int n=1;n<=N;n++)
    {
        sum += 1.0/(2*n*(2*n+1));
    }
    return sum;
}
