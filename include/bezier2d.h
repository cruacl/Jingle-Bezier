#pragma once
#include <cmath>

#define PI 3.141592653589793238 

struct point2D {
	float x;
	float y;

};

struct vector2D {
	float x;
	float y;
	float length()const {
		return sqrt(x * x + y * y);
	}
	vector2D normalize() const {
		float len = length();
		if (len == 0.0f) {
			return { 0.0f, 0.0f };
		}
		return{ x / len,
			    y / len
		};
	}
};



class bezier2D {
private:
	point2D p0, p1, p2, p3;

public:
	bezier2D(point2D p0, point2D p1, point2D p2, point2D p3) {
	
		 this->p0 = p0;
		 this->p1 = p1;
		 this->p2 = p2;
		 this->p3 = p3;
	};
	point2D Evaluate(float t) {
	
		float time = 1 - t;

		point2D point;
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

		return point;

	};

	vector2D Derivative(float t) {
		
		float  time = 1 - t;
		vector2D result;

		result.x = 3* time * time* (p1.x - p0.x) + 
			6 * time * t * (p2.x - p1.x) + 3 * t*t * (p3.x - p2.x);
		
		result.y = 3 * time * time * (p1.y - p0.y) +
			6 * time * t * (p2.y - p1.y) + 3 * t * t * (p3.y - p2.y);


		return result;
	};
	vector2D tangent(float t) {
		vector2D tangent = Derivative(t);
		return tangent.normalize();
	}

	float angle(float t) {
		vector2D angle = tangent(t);
		float ang = atan2(angle.y, angle.x);
		return (ang * 180) / PI;

	}
	vector2D SecondDerivative(float t) {
		vector2D result;
		float time = 1 - t;

		result.x = 6 * time * (p2.x - 2 * p1.x + p0.x) + 6 * t *
			(p3.x - 2 * p2.x + p1.x);
		result.y = 6 * time * (p2.y - 2 * p1.y + p0.y) + 6 * t *
			(p3.y - 2 * p2.y + p1.y);

		return result;
	}

	float Curvature(float t) {
		vector2D Dr = Derivative(t);
		vector2D SecDr = SecondDerivative(t);

		float o = (Dr.x * SecDr.y) - (Dr.y * SecDr.x);
		float i = (Dr.x * Dr.x) + (Dr.y * Dr.y);
		float p = sqrt(i);
		float w = p * p * p;
		if(w == 0.0f){
			return 0.0f;
		}
		return o / w;
	};

	void setp0(point2D p0) {
		this->p0 = p0;
		};
	void setp1(point2D p1) {
		this->p1 = p1;
	};
	void setp2(point2D p2) {
		this->p2 = p2;
	};
	void setp3(point2D p3) {
		this->p3 = p3;
	};
	point2D getp0() const {
		

		return p0;
	};
	point2D getp1() const {


		return p1;
	};
	point2D getp2() const {


		return p2;
	};
	point2D getp3() const {


		return p3;
	};
};



