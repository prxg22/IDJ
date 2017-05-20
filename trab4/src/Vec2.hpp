#ifndef VEC2_HPP
#define VEC2_HPP

#include <cmath>
#include <cstdio>

#define PI 3.14159265359f
#define DEG2RAD(x) (PI * x / 180.0f)
#define RAD2DEG(x) (180.0f * x / PI)

template <typename T>
class Vec2{

public:
	T x, y, z;

	Vec2(T x = 0, T y = 0, T z = 0);
	
	Vec2 operator+(const Vec2& o) const;
	Vec2& operator+=(const Vec2& o);
	Vec2 operator-() const;
	Vec2 operator-(const Vec2& o) const;
	Vec2& operator-=(const Vec2& o);
	Vec2& operator*=(T o);
	Vec2 operator*(T o) const;
	Vec2& operator/=(T o);
	Vec2 operator/(T o) const;


	float norm() const;
	float size() const;
	float length() const;
	float len() const;
	
	T norm2() const;
	T size2() const;
	T length2() const;
	T len2() const;
	
	T dot(const Vec2& o) const;
	
	Vec2 rotate(float deg) const;
	static Vec2 zero();
	Vec2 unitVec() const;
};

typedef Vec2<float>	Vec2f;
typedef Vec2<int>	Vec2i;

#include "Vec2.cpp.hpp"

#endif