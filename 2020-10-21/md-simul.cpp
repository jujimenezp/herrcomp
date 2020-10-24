#include "md-simul.h"

void initial_conditions(Particle & body)
{
  body.Ry = 1.6598;
  body.Vx = 0.53698;
  body.Vy = 0.26454;
  body.Vz = 0.3345;

  body.rad = 0.235;
  body.mass = 0.39698;
}

void compute_force(Particle & body)
{
  // reset force
  body.Fx = body.Fy = body.Fz = 0.0;

  // gravitational force
  body.Fy += body.mass*G;

  // force with ground
  double delta = body.rad - body.Ry;
  if (delta > 0) {
    body.Fy += K*delta;
    body.Fy -= 1.9876*body.Vy;
  }

  // force with right wall x axis
  delta = fabs(body.Rx) + body.rad - fabs(LXr);
  if (delta > 0) {
    body.Fx -= K*delta;
    body.Fx -= 0.2*body.Vx;
  }

  // force with left wall x axis
  delta = fabs(body.Rx) + body.rad - fabs(LXl);
  if (delta > 0) {
    body.Fx += K*delta;
    body.Fx -= 0.2*body.Vx;
  }

  // force with right wall z axis
  delta = fabs(body.Rz) + body.rad - fabs(LZr);
  if (delta > 0) {
    body.Fz -= K*delta;
    body.Fz -= 0.2*body.Vz;
  }

  // force with left wall z axis
  delta = fabs(body.Rz) + body.rad - fabs(LZl);
  if (delta > 0) {
    body.Fz += K*delta;
    body.Fz -= 0.2*body.Vz;
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
