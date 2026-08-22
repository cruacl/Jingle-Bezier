#pragma once
#include <cmath>



struct point3D {
	float x;
	float y;
	float z;
};
struct vector3D {
	float x;
	float y;
	float z;
	float length()const {
		return sqrt(x * x + y * y + z * z);
	}
	vector3D normalize()const {
		float len = length();
		if (len == 0.0f) {
			return { 0.0f, 0.0f, 0.0f };
		}
		return{ x / len,
				y / len,
				z / len
		};
	}
};

vector3D CrossProduct(vector3D dr, vector3D secdr) {

		vector3D result;

		result.x = (dr.y * secdr.z) - (dr.z * secdr.y);
		result.y = (dr.z * secdr.x) - (dr.x * secdr.z);
		result.z = (dr.x * secdr.y) - (dr.y * secdr.x);

		return result;

}


class bezier3D
{

private:
	point3D p0, p1, p2, p3;

public:
	bezier3D(point3D p0, point3D p1, point3D p2, point3D p3) {
		this->p0 = p0;
		this->p1 = p1;
		this->p2 = p2;
		this->p3 = p3;

	};


	point3D Evaluate(float t) {

		float time = 1 - t;

		point3D point;
		point.x =
			time * time * time * p0.x +
			3 * time * time * t * p1.x +
			3 * time * t * t * p2.x +
			t * t * t * p3.x;
		point.y =
			time * time * time * p0.y +
			3 * time * time * t * p1.y +
			3 * time * t * t * p2.y +
			t * t * t * p3.y;
		point.z =
			time * time * time * p0.z +
			3 * time * time * t * p1.z +
			3 * time * t * t * p2.z +
			t * t * t * p3.z;

		return point;

	};
	vector3D Derivative(float t) {

		float  time = 1 - t;
		vector3D result;

		result.x = 3 * time * time * (p1.x - p0.x) +
			6 * time * t * (p2.x - p1.x) + 3 * t * t * (p3.x - p2.x);

		result.y = 3 * time * time * (p1.y - p0.y) +
			6 * time * t * (p2.y - p1.y) + 3 * t * t * (p3.y - p2.y);

		result.z = 3 * time * time * (p1.z - p0.z) +
			6 * time * t * (p2.z - p1.z) + 3 * t * t * (p3.z - p2.z);


		return result;
	};
	vector3D SecondDerivative(float t) {
		vector3D result;
		float time = 1 - t;

		result.x = 6 * time * (p2.x - 2 * p1.x + p0.x) + 6 * t *
			(p3.x - 2 * p2.x + p1.x);
		result.y = 6 * time * (p2.y - 2 * p1.y + p0.y) + 6 * t *
			(p3.y - 2 * p2.y + p1.y);
		result.z = 6 * time * (p2.z - 2 * p1.z + p0.z) + 6 * t *
			(p3.z - 2 * p2.z + p1.z);


		return result;
	}
	float Curvature(float t) {
		vector3D Dr = Derivative(t);
		vector3D SecDr = SecondDerivative(t);

		vector3D cross = CrossProduct(Dr, SecDr);
		float numerator = cross.length();

		float Denominator = Dr.length() * Dr.length() * Dr.length();

		if (Denominator == 0.0f) {
			return 0.0f;
		}
		return numerator / Denominator;
	};

	void setp0(point3D p0) {
		this->p0 = p0;
	};
	void setp1(point3D p1) {
		this->p1 = p1;
	};
	void setp2(point3D p2) {
		this->p2 = p2;
	};
	void setp3(point3D p3) {
		this->p3 = p3;
	};
	point3D getp0() const {


		return p0;
	};
	point3D getp1() const {


		return p1;
	};
	point3D getp2() const {


		return p2;
	};
	point3D getp3() const {


		return p3;
	};

};
