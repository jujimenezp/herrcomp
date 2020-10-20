#include <iostream>
#include <vector>

//Estre programa simula un cuerpo que cae bajo accion de la gravedad y
//en el futuro va a rebotar contra el suelo y contra otros cuerpos

//Cuerpo
struct body {
    double masa;
    double r[3], v[3], f[3];

    void initial_conditions(std::vector<body> & bodies);
    void timestep(std::vector<body> & bodies, double dt);
    void start_timeintegration(std::vector<body> & bodies, double dt);
    void compute_force(std::vector<body> & bodies, double dt);
    void print_system(std::vector<body> & bodies, double time);
    
};

//Simulation conditions
const int N = 1;
const double g = 9.81;

/*
Cuerpo:
   -masa(densidad)
   -(forma :esfera)
   -r[3], v[3], F[3]

   Condiciones externas
   - Gravedad
   
   Funciones
   -initial_conditions

   -timestep (nueva posicon y nueva velocidad)
   -start_timeintegration()
   -Compute_force
     -Gravedad
   -print_system

   -Visualization
*/

int main(){
    
    std::vector<body> bodies[N];
    return 0;
}
