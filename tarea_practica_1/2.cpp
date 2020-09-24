//computing arctan x

# include <cmath>
# include <cstdlib>
# include <iostream>

double myatan(double x, int n);

int main(int argc, char **argv)
{
std::cout.precision(15); std::cout.setf(std::ios::scientific);
const int NSTEPS = std::atoi(argv[1]);// 53
const double x = std::atof(argv[2]); // 4.2
const double exact = std::atan(x);
double my = myatan(x, NSTEPS);
double diff = std::fabs(my-exact)/exact;
std::cout << exact << "\t" << my << std::endl;
std::cout << diff << std::endl;
return 0;
}

double myatan(double x, int n){
    double a=std::pow(2.0,-n/2.0);
    double b=x/(1+std::sqrt(1+x*x));
    double c=1.0, d=1.0;
    double f=0.0;
    do {
        c = 2.0*c/(1+a);
        d = 2.0*a*b/(1+b*b);
        d = d/(1+std::sqrt(1-d*d));
        d = (b+d)/(1-b*d);
        b = d/(1+std::sqrt(1+d*d));
        a = 2*std::sqrt(a)/(1+a);
        f = c*std::log((1+b)/(1-b));
        
    }
    while((1-a) > std::pow(2.0,-n));
    return f;
}
