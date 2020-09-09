#include "sum.h"

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
