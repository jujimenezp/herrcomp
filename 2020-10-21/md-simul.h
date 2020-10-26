#ifndef __MD_SIMUL_H_
#define __MD_SIMUL_H_

#include <iostream>
#include <cmath>
#include "particle.h"

const double G = -9.81;
const int NSTEPS = 1000;
const double DT = 0.01;
const double K = 500.57;
const double LY = 3.0;
const double LXr = 2.01;
const double LXl = -1.5;
const double LZr = 2.01;
const double LZl = -1.5;

// function declarations
void initial_conditions(Particle & body);
void compute_force(Particle & body);
void time_integration(Particle & body, const double & dt);
void start_integration(Particle & body, const double & dt);
void print(Particle & body, double time);

#endif // __MD_SIMUL_H_
