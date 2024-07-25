#include "pch.h"
#include "Vector3.h"
#include <cmath>

Vector3::Vector3() : D2D1_VECTOR_3F{ 0.0f, 0.0f, 0.0f } {}

Vector3::Vector3(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
}

const float Vector3::Magnitude() const
{
	return sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::Normalized() const
{
	if (Magnitude() == 0) return Vector3();
	return *this / Magnitude();
}

const float dot(Vector3& a, Vector3& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 Cross(Vector3& a, Vector3& b)
{
	return Vector3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}

void Vector3::operator=		(const Vector3& v) {
	x = v.x;
	y = v.y;
	z = v.z;
}

Vector3 Vector3::operator+=	(const Vector3& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vector3 Vector3::operator-=	(const Vector3& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vector3 Vector3::operator*=	(const float& scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

Vector3 Vector3::operator/=	(const float& scalar) {
	x /= scalar;
	y /= scalar;
	z /= scalar;
	return *this;
}

Vector3 Vector3::operator+	(const Vector3& v) const {
	return Vector3(*this) += v;
}

Vector3 Vector3::operator-	(const Vector3& v) const {
	return Vector3(*this) -= v;
}

Vector3 Vector3::operator*	(const float& scalar) const {
	return Vector3(*this) *= scalar;
}

Vector3 Vector3::operator/	(const float& scalar) const {
	return Vector3(*this) /= scalar;
}

bool Vector3::operator==(const Vector3& v) const
{
	return ((x == v.x) && (y == v.y) && (z == v.z));
}
