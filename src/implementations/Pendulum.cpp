/*
 * Pendulum.cpp
 *
 *  Created on: Feb 24, 2023
 *      Author: norms
 */

#include "../headers/Pendulum.h"
#include "Vectors.h"

// Methods that act on the Pendulum Struct

// Initialize a Pendulum
Pendulum *initializePendulum(Circular_Rigid_Body *masses, int numMasses, Rigid_Bar_1 bar1, Rigid_Bar_2 *bar2s, int numBar2s)
{
	// Allocate space
	Pendulum *p = (Pendulum *)malloc(sizeof(Pendulum));

	// Set the masses
	p->masses = masses;
	p->numMasses = numMasses;

	// Set the pivot bar
	p->bar1 = bar1;

	// Set the bars connecting the masses if there are any
	p->numBar2s = numBar2s;
	if (p->numBar2s > 0)
	{
		p->bar2s = bar2s;
	}

	// Set the angles for the Pendulum
	p->numAngles = numMasses;
	p->angles = (double *)malloc(p->numAngles * sizeof(double));

	// Set pendulum angles
	p->angles = findPendulumAngles(p);

	return p;
}

// Return a double array of all angles for a pendulum
double *findPendulumAngles(Pendulum *p)
{
	// Allocate for the result
	double *angles = (double *)malloc(p->numAngles * sizeof(double));

	// Angle for bar between pivot and first mass
	Vector v = {p->masses[0].pos.x - p->bar1.pivot.x, p->masses[0].pos.y - p->bar1.pivot.y};
	Vector vert = {0, -1};
	angles[0] = angle_between_vectors(v, vert);

	// Find the rest of the angles
	if (p->numAngles > 1)
	{
		for (int i = 1; i < p->numMasses; ++i)
		{
			v = {p->masses[i].pos.x - p->masses[i - 1].pos.x, p->masses[i].pos.y - p->masses[i - 1].pos.y};
			angles[i] = angle_between_vectors(v, vert);
		}
	}

	return angles;
}
//

