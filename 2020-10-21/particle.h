#ifndef __PARTICLE_H_
#define __PARTICLE_H_

struct Particle
{
  double rad = 0.0;
  double mass = 0.0;
  double Rx = 0.0, Ry = 0.0, Rz = 0.0;
  double Vx = 0.0, Vy = 0.0, Vz = 0.0;
  double Fx = 0.0, Fy = 0.0, Fz = 0.0;
  
  double Eelas = 0.0;
  double energy(double G)
  {
    //Reinicar E
    double E = 0.0;

    //Potencial gravitacional
    E += Ry*mass*fabs(G);

    //Energia cinetica
    E += mass*(Vx*Vx+Vy*Vy+Vz*Vz)/2;

    return E;

  }
  
};


#endif // __PARTICLE_H_
