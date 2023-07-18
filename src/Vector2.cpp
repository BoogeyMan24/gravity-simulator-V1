#include "Vector2.h"


Vector2::Vector2() {
	this->x = 0;
	this->y = 0;	
}


Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;	
}


void Vector2::normalized() {
	float mag = this->magnitude();

	if (mag == 0) {
		divisionByZero();
		return;
	}

	x = x / mag;
	y = y / mag;
}

float Vector2::distance(Vector2 vec) {
	return std::sqrt(std::pow((vec.x - this->x), 2) + std::pow((vec.y - this->y), 2));
}

float Vector2::distance(float x, float y) {
	return std::sqrt(std::pow((x - this->x), 2) + std::pow((y - this->y), 2));
}

Vector2 Vector2::direction(Vector2 vec) {
	return Vector2(vec.x - this->x, vec.y - this->y);
}


void Vector2::setMagnitude(float new_magnitude) {
	if (new_magnitude == 0) {
		divisionByZero();
		return;
	}

	float n = this->magnitude() / new_magnitude;

	if (n == 0) {
		divisionByZero();
		return;
	}

	this->x = this->x / n;
	this->y = this->y / n;
}


float Vector2::magnitude() {
	return std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2));
}


void Vector2::divisionByZero() {
	std::cout << "Division by zero: Vector2 class" << std::endl;
}



Vector2 Vector2::operator=(Vector2 vec) { return Vector2(x = vec.x, y = vec.y); }
Vector2 Vector2::operator=(float n) { return Vector2(x = n, y = n); }

Vector2 Vector2::operator+(Vector2 vec) { return Vector2(x + vec.x, y + vec.y); }
Vector2 Vector2::operator+(float n) { return Vector2(x + n, y + n); }

Vector2 Vector2::operator-(Vector2 vec) { return Vector2(x - vec.x, y - vec.y); }
Vector2 Vector2::operator-(float n) { return Vector2(x - n, y - n); }

Vector2 Vector2::operator*(Vector2 vec) { return Vector2(x * vec.x, y * vec.y); }
Vector2 Vector2::operator*(float n) { return Vector2(x * n, y * n); }

Vector2 Vector2::operator/(Vector2 vec) { return Vector2(x / vec.x, y / vec.y); }
Vector2 Vector2::operator/(float n) { return Vector2(x / n, y / n); }


Vector2 Vector2::operator+=(Vector2 vec) { return Vector2(x += vec.x, y += vec.y); }
Vector2 Vector2::operator+=(float n) { return Vector2(x += n, y += n); }

Vector2 Vector2::operator-=(Vector2 vec) { return Vector2(x -= vec.x, y -= vec.y); }
Vector2 Vector2::operator-=(float n) { return Vector2(x -= n, y -= n); }

Vector2 Vector2::operator*=(Vector2 vec) { return Vector2(x *= vec.x, y *= vec.y); }
Vector2 Vector2::operator*=(float n) { return Vector2(x *= n, y *= n); }

Vector2 Vector2::operator/=(Vector2 vec) { return Vector2(x /= vec.x, y /= vec.y); }
Vector2 Vector2::operator/=(float n) { return Vector2(x /= n, y /= n); }
