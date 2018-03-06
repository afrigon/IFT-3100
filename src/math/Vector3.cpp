//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "math/Vector3.h"

Vector3::Vector3(): x(0), y(0), z(0) {}
Vector3::Vector3(float value): x(value), y(value), z(value) {}
Vector3::Vector3(float x, float y, float z): x(x), y(y), z(z) {}

Vector3 Vector3::operator+(const Vector3 &u) {
    return Vector3(this->x + u.getX(), this->y + u.getY(), this->z + u.getZ());
}

Vector3& Vector3::operator+=(const Vector3 &u) {
    this->x += u.getX();
    this->y += u.getY();
    this->z += u.getZ();
    return *this;
}

Vector3 Vector3::operator-(const Vector3 &u) {
    return Vector3(this->x - u.getX(), this->y - u.getY(), this->z - u.getZ());
}

Vector3& Vector3::operator-=(const Vector3 &u) {
    this->x -= u.getX();
    this->y -= u.getY();
    this->z -= u.getZ();
    return *this;
}

Vector3 Vector3::operator-() {
    return Vector3(-this->x, -this->y, -this->z);
}

Vector3 Vector3::operator*(const float &s) {
    return Vector3(this->x * s, this->y * s, this->z * s);
}

Vector3& Vector3::operator*=(const float &s) {
    this->x *= s;
    this->y *= s;
    this->z *= s;
    return *this;
}

float Vector3::operator*(const Vector3 &u) {
    return (this->x * u.getX()) + (this->y * u.getY()) + (this->z * u.getZ());
}

Vector3 Vector3::operator/(const float &s) {
    return Vector3(this->x / s, this->y / s, this->z / s);
}

Vector3& Vector3::operator/=(const float &s) {
    this->x /= s;
    this->y /= s;
    this->z /= s;
    return *this;
}

Vector3 Vector3::operator^(const Vector3 &u) {
    float nx = (this->y * u.getZ()) - (this->z * u.getY());
    float ny = (this->z * u.getX()) - (this->x * u.getZ());
    float nz = (this->x * u.getY()) - (this->y * u.getX());
    return Vector3(nx, ny, nz);
}

Vector3& Vector3::operator^=(const Vector3 &u) {
    this->x = (this->y * u.getZ()) - (this->z * u.getY());
    this->y = (this->z * u.getX()) - (this->x * u.getZ());
    this->z = (this->x * u.getY()) - (this->y * u.getX());
    return *this;
}

float Vector3::getX() const { return this->x; }
float Vector3::getY() const { return this->y; }
float Vector3::getZ() const { return this->z; }

float Vector3::magnitude() {
    return sqrt((x * x) + (y * y) + (z * z));
}

Vector3 Vector3::normalised() {
    float m = this->magnitude();
    if (m == 0) return Vector3(*this);
    return Vector3(*this) / m;
}

Vector3& Vector3::normalise() {
    float m = this->magnitude();
    if (m != 0) (*this) /= m;
    return *this;
}
