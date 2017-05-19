
template <typename T>
Vec2<T>::Vec2(T x, T y, T z) : x(x), y(y), z(z) {}

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
