#include "Point3d.h"	//Should have inserted this after #define VECTOR3D_h
#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3d
{
private:
	double m_x;		//Again, should be m_x[];
	double m_y;
	double m_z;

public:
	Vector3d(double x = 0.0, double y = 0.0, double z = 0.0);

	void print() const;

	friend void Point3d::moveByVector(const Vector3d& v);
};

#endif
