//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef MATH_VECTOR3_H_
#define MATH_VECTOR3_H_

#include <cmath>
#include <string>

class Vector3 {
    float x;
    float y;
    float z;

    int round(float) const;
    
 public:
    Vector3();
    explicit Vector3(float);
    Vector3(float, float, float);

    Vector3 operator+(const Vector3 &);
    Vector3& operator+=(const Vector3 &);

    Vector3 operator-(const Vector3 &);
    Vector3& operator-=(const Vector3 &);
    Vector3 operator-();  // inversed

    Vector3 operator*(const float &);
    Vector3& operator*=(const float &);
    float operator*(const Vector3 &);  // dot

    Vector3 operator/(const float &);
    Vector3& operator/=(const float &);

    Vector3 operator^(const Vector3 &);  // cross
    Vector3& operator^=(const Vector3 &);  // assigned cross

    float getX() const;
    float getY() const;
    float getZ() const;

    float magnitude();

    Vector3 normalised();
    Vector3& normalise();
};

#endif  // MATH_VECTOR3_H_
