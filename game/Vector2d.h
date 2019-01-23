#pragma once
#include<iostream>

class Vector2d
{
public:
	int x = 0;
	int y = 0;

	Vector2d() = default;
	Vector2d(int x, int y);
	~Vector2d() = default;

	Vector2d& add(const Vector2d &);
	Vector2d& sub(const Vector2d &);
	Vector2d& mul(const Vector2d &);
	Vector2d& div(const Vector2d &);

	friend Vector2d& operator+(Vector2d&, const Vector2d&);
	friend Vector2d& operator-(Vector2d&, const Vector2d&);
	friend Vector2d& operator*(Vector2d&, const Vector2d&);
	friend Vector2d& operator/(Vector2d&, const Vector2d&);

	Vector2d& operator+=(const Vector2d&);
	Vector2d& operator-=(const Vector2d&);
	Vector2d& operator*=(const Vector2d&);
	Vector2d& operator/=(const Vector2d&);

	friend std::ostream& operator<<(std::ostream&, const Vector2d&);
};

