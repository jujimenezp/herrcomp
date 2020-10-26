#include "md-simul.h"
#include <string>
#include <fstream>

int main(void)
{
  Particle ball;

  // start system
  double E = 0.0;
  initial_conditions(ball);
  compute_force(ball);
  start_integration(ball, DT);
  print(ball, 0.0);

  // evolve
  for(int istep = 0; istep < NSTEPS; ++istep) {
    time_integration(ball, DT);
    compute_force(ball);
    E = ball.energy(G)+ball.Eelas;
    //print(ball, istep*DT);
    if(istep%2 == 0){
      std::string fname = "post/datos-"+std::to_string(istep/2)+".csv";
      std::ofstream fout(fname);
      fout  << ball.Rx << ", "
            << ball.Ry << ", "
            << ball.Rz << ", "
            << ball.mass << ", "
            << ball.rad << "\n";
    }
    std::cout << istep << "\t"
              << E << "\n";
  }

  return 0;
}
