#include "Vector2d.h"
#include<cmath>


Vector2d::Vector2d(int x, int y):
	x(x),
	y(y)
{}

Vector2d & Vector2d::add(const Vector2d & vec){
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

Vector2d & Vector2d::sub(const Vector2d & vec){
	this->x -= vec.x;
	this->y -= vec.y;
	return *this;
}

Vector2d & Vector2d::mul(const Vector2d & vec){
	this->x *= vec.x;
	this->y *= vec.y;
	return *this;
}

Vector2d & Vector2d::div(const Vector2d &vec){
	this->x = static_cast<int>(round(this->x / static_cast<float>(vec.x)));
	this->y = static_cast<int>(round(this->y / static_cast<float>(vec.y)));
	return *this;
}

Vector2d & Vector2d::operator+=(const Vector2d & vec){
	return this->add(vec);
}

Vector2d & Vector2d::operator-=(const Vector2d &vec){
	return this->sub(vec);
}

Vector2d & Vector2d::operator*=(const Vector2d &vec){
	return this->mul(vec);
}

Vector2d & Vector2d::operator/=(const Vector2d &vec){
	return this->div(vec);
}

Vector2d & operator+(Vector2d &vec1, const Vector2d & vec2){
	return vec1.add(vec2);
}
Vector2d & operator-(Vector2d & vec1, const Vector2d & vec2){
	return vec1.sub(vec2);
}
Vector2d & operator*(Vector2d & vec1, const Vector2d & vec2){
	return vec1.mul(vec2);
}
Vector2d & operator/(Vector2d &vec1, const Vector2d & vec2){
	return vec1.div(vec2);
}

std::ostream & operator<<(std::ostream & os, const Vector2d & vec){
	os << "(" << vec.x << ", " << vec.y << ")";
	return os;
}
