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
	T x, y;

	Vec2();
	Vec2(T x, T y);
	
	Vec2 operator+(const Vec2& o) const;
	Vec2& operator+=(const Vec2& o);
	Vec2 operator-() const;
	Vec2 operator-(const Vec2& o) const;
	Vec2& operator-=(const Vec2& o);
	Vec2& operator*=(T o);
	Vec2 operator*(T o) const;


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
};

typedef Vec2<float>	Vec2f;
typedef Vec2<int>	Vec2i;

template <typename T>
Vec2<T>::Vec2() : x(0), y(0) {}

template <typename T>
Vec2<T>::Vec2(T x, T y) : x(x), y(y) {}

template <typename T>
Vec2<T> Vec2<T>::operator+(const Vec2& o) const {
	Vec2<T> v = *this;
	v += o;
	return v;
}

template <typename T>
Vec2<T>& Vec2<T>::operator+=(const Vec2& o){
	x += o.x;
	y += o.y;
	return *this;
}

template <typename T>
Vec2<T> Vec2<T>::operator-() const {
	Vec2<T> v = *this;
	v.x = -v.x;
	v.y = -v.y;
	return v;
}

template <typename T>
Vec2<T> Vec2<T>::operator-(const Vec2& o) const {
	Vec2<T> v = *this;
	v -= o;
	return v;
}

template <typename T>
Vec2<T>& Vec2<T>::operator-=(const Vec2& o) {
	*this += -o;
	return *this;
}

template <typename T>
Vec2<T>& Vec2<T>::operator*=(T o) {
	x *= o;
	y *= o;
	
	return *this;
}

template <typename T>
Vec2<T> Vec2<T>::operator*(T o) const {
	Vec2 v = *this;
	v *= o;
	return v;
}

template <typename T>
float Vec2<T>::norm() const {
	return sqrt(x*x + y*y);
}
template <typename T>
float Vec2<T>::size() const {
	return norm();
}
template <typename T>
float Vec2<T>::length() const{
	return norm();
}
template <typename T>
float Vec2<T>::len() const{
	return norm();
}

template <typename T>
T Vec2<T>::norm2() const{
	return x*x + y*y;
}
template <typename T>
T Vec2<T>::size2() const{
	return norm2();
}
template <typename T>
T Vec2<T>::length2() const{
	return norm2();
}
template <typename T>
T Vec2<T>::len2() const{
	return norm2();
}

template <typename T>
Vec2<T> Vec2<T>::rotate(float deg) const {
	Vec2<T> v;
	float rad = DEG2RAD(deg);
	float c = cos(rad), s = sin(rad);
	
	v.x = x * c - y * s;
	v.y = y * c + x * s;
	
	return v;
}

template <typename T>
T Vec2<T>::dot(const Vec2& o) const {
	return x * o.x + y * o.y;
}



#endif