
// Include header of Vector class because there are actual variables being defined
#include "vectors.h"

#ifndef MASS_H_
#define MASS_H_

#include "constraint_bodies.h"

// Class for a circular rigid body
class Circular_Rigid_Body
{
	public:
	Vector pos;
	double angle;
	Vector linear_vel;
	double angular_vel;
	Vector force_ext;
	double torque;
	double mass;
	double radius;
	double moi;

	void determine_moi(void);

	void set_initial_force_ext(void);
};



#endif /* MASS_H_ */
