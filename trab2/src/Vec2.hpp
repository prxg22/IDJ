#ifndef VEC2_HPP
#define VEC2_HPP

#include <cmath>
#include <cstdio>

template <typename T>
class Vec2{

public:
	T x, y;

	Vec2();
	Vec2(T x, T y);
	
	Vec2 operator+(const Vec2& o) const;
	Vec2& operator+=(const Vec2& o);

	float norm() const;
	float size() const;
	float length() const;
	float len() const;
	
	T norm2() const;
	T size2() const;
	T length2() const;
	T len2() const;
};

typedef Vec2<float>	Vec2f;
typedef Vec2<int>	Vec2i;

template <typename T>
Vec2<T>::Vec2() : x(0), y(0) {
	printf("vazio\n");
}

template <typename T>
Vec2<T>::Vec2(T x, T y) : x(x), y(y) {
	printf("show (%.2f, %.2f)\n", x, y);
}

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


#endif