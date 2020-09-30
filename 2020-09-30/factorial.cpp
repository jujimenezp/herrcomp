//function definition or implementation
#include <iostream>
#include "factorial.h"

long factorial(long n)
{
    if (n<0){
        std::cerr << "ERROR: Cannot ocmpute factorial for negative numbers. Received n: "
                  << n << "\n";
        return 0;
    }
    
    return n <= 1 ? n : n*factorial(n-1);
}
