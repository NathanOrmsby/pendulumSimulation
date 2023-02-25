#include "../headers/vectors.h"
#include "../headers/renderer.h"
#include "../headers/rigid_bodies.h"

// Class for a mass that acts like a point mass, and is drawn in the shape of a circle

void Circular_Rigid_Body::determine_moi(void)
{
	moi = (mass * (radius * radius)) / 2.0;
}

void Circular_Rigid_Body::set_initial_force_ext(void)
{
	// Initial external force is gravitational
	// Gravitational
	force_ext.y = mass * -9.8;
	force_ext.x = 0.0;
	torque = 0.0;

	// Then apply spring force if a spring is attached using the spring class method
}





