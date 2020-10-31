#include <iostream>
#include <omp.h>

int main(int argc, char **argv)
{
#pragma omp parallel
    {
        int tid = omp_get_thread_num();
        int nth = omp_get_num_threads();
        std::cout << "My tid: " << tid << std::endl;
        std::cout << "My nth: " << nth << std::endl;
        std::cout << "&tid :" << &tid << std::endl;
        std::cout << "hello world, from tid: " << tid  << std::endl;
    }
    return 0;
}
