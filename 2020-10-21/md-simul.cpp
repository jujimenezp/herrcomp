#include "md-simul.h"

void initial_conditions(Particle & body)
{
  body.Ry = 1.6598;
  body.Vx = 5.83698;
  body.Vy = 10.56454;
  body.Vz = 6.1345;

  body.rad = 0.235;
  body.mass = 0.39698;
}

void compute_force(Particle & body, double & Eelas)
{
  // reset force
  body.Fx = body.Fy = body.Fz = 0.0;

  // reset elastic energy
  Eelas = 0.0;

  // gravitational force
  body.Fy += body.mass*G;

  // force with ground
  double delta = body.rad - body.Ry;
  if (delta > 0) {
    body.Fy += K*delta;
    body.Fy -= 1.9876*body.Vy;
    Eelas += K*delta*delta/2;
  }

   // force with ceiling
  delta = body.Ry + body.rad - LY;
  if (delta > 0) {
    body.Fy -= K*delta;
    body.Fy -= 0.2*body.Vy;
    Eelas += K*delta*delta/2;
  }

  // force with right wall x axis
  delta = body.Rx + body.rad - LXr;
  if (delta > 0) {
    body.Fx -= K*delta;
    body.Fx -= 0.2*body.Vx;
    Eelas += K*delta*delta/2;
  }

  // force with left wall x axis
  delta = -body.Rx + body.rad + LXl;
  if (delta > 0) {
    body.Fx += K*delta;
    body.Fx -= 0.2*body.Vx;
    Eelas += K*delta*delta/2;
  }

  // force with right wall z axis
  delta = body.Rz + body.rad - LZr;
  if (delta > 0) {
    body.Fz -= K*delta;
    body.Fz -= 0.2*body.Vz;
    Eelas += K*delta*delta/2;
  }

  // force with left wall z axis
  delta = -body.Rz + body.rad + LZl;
  if (delta > 0) {
    body.Fz += K*delta;
    body.Fz -= 0.2*body.Vz;
    Eelas += K*delta*delta/2;
  }
}

void start_integration(Particle & body, const double & dt)
{
  body.Vx -= body.Fx*dt/(2*body.mass);
  body.Vy -= body.Fy*dt/(2*body.mass);
  body.Vz -= body.Fz*dt/(2*body.mass);
}

  void time_integration(Particle & body, const double & dt)
{
  // leap-frog
  body.Vx += body.Fx*dt/(body.mass);
  body.Vy += body.Fy*dt/(body.mass);
  body.Vz += body.Fz*dt/(body.mass);
  body.Rx += body.Vx*dt;
  body.Ry += body.Vy*dt;
  body.Rz += body.Vz*dt;
}

double energy(Particle body)
{
  //Reinicar E
  double E = 0.0;

  //Potencial gravitacional
  E += body.Ry*body.mass*fabs(G);

  //Energia cinetica
  E += body.mass*(body.Vx*body.Vx+body.Vy*body.Vy+body.Vz*body.Vz)/2;

  return E;

}
  

void print(Particle & body, double time)
{
  std::cout << time << "  "
            << body.Rx << "  "
            << body.Ry << "  "
            << body.Rz << "  "
            << body.Vx << "  "
            << body.Vy << "  "
            << body.Vz << "  "
            << "\n";
}
