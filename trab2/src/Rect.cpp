#include "Rect.hpp"

Rect::Rect() : x(0), y(0), w(0), h(0) {}
Rect::Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {}

bool Rect::isInside(float x, float y) const {
	return (this->x <= x  && x <= this->x + w) && (this->y <= y  && y <= this->y + h);
}