/*
 * Pendulum.h
 *
 *  Created on: Feb 24, 2023
 *      Author: norms
 */

#ifndef HEADERS_PENDULUM_H_
#define HEADERS_PENDULUM_H_

#include "rigid_bodies.h"
#include "get_state.h"

// Class for a pendulum, encapsulates a collection of masses and rigid bars
typedef struct Pendulum
{
	// Masses
	Circular_Rigid_Body *masses;
	int numMasses;

	// Rigid bars
	Rigid_Bar_1 bar1;
	Rigid_Bar_2 *bar2s;
	int numBar2s;

	// To get current state
	State_Getter state;

	// Angles
	double *angles;
	int numAngles;

	// Pointer for perturbations if desired
	Pendulum *perturbed;
};


// Methods for Pendulum

// Initialize a Pendulum
Pendulum *initializePendulum(Circular_Rigid_Body *masses, int numMasses, Rigid_Bar_1 bar1, Rigid_Bar_2 *bar2s, int numBar2s);

// Return a double array of all angles for a pendulum
double *findPendulumAngles(Pendulum *p);

#endif /* HEADERS_PENDULUM_H_ */
