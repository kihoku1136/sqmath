#include <sq_vector3.h>
#include <sq_math_utility.h>
#include <cassert>
namespace sqmath
{
template< typename T >
inline constexpr TVector3<T>::TVector3(T inValue)
	: TVector3(inValue, inValue, inValue)
{
}

template< typename T >
inline constexpr TVector3<T>::TVector3(T inX, T inY, T inZ)
	: x{ inX }
	, y{ inY }
	, z{ inZ }
{
}

template<typename T>
inline constexpr TVector3<T> TVector3<T>::operator+(const TVector3& v) const
{
	return{ x + v.x, y + v.y, z + v.z };
}

template<typename T>
inline constexpr TVector3<T> TVector3<T>::operator+(const T bias) const
{
	return{ x + bias, y + bias, z + bias };
}

template<typename T>
inline TVector3<T> TVector3<T>::operator+=(const TVector3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

template<typename T>
inline constexpr TVector3<T> TVector3<T>::operator-(const TVector3& v) const
{
	return{ x - v.x, y - v.y, z - v.z };
}

template<typename T>
inline constexpr TVector3<T> TVector3<T>::operator-(const T bias) const
{
	return{ x - bias, y - bias, z - bias };
}

template<typename T>
inline constexpr TVector3<T> TVector3<T>::operator-() const
{
	return{ -x, -y, -z };
}

template<typename T>
inline TVector3<T> TVector3<T>::operator-=(const TVector3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

template<typename T>
inline constexpr TVector3<T> TVector3<T>::operator*(const TVector3& v) const
{
	return{ x * v.x, y * v.y, z * v.z };
}

template<typename T>
inline constexpr TVector3<T> TVector3<T>::operator*(const T scale) const
{
	return{ x * scale, y * scale, z * scale };
}

template<typename T>
inline TVector3<T> TVector3<T>::operator*=(const TVector3& v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}

template<typename T>
inline constexpr TVector3<T> TVector3<T>::operator/(const TVector3& v) const
{
	return{ x / v.x, y / v.y, z / v.z };
}

template<typename T>
inline constexpr TVector3<T> TVector3<T>::operator/(const T scale) const
{
	return{ x / scale, y / scale, z / scale };
}

template<typename T>
inline TVector3<T> TVector3<T>::operator/=(const TVector3& v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	return *this;
}

template<typename T>
inline constexpr bool TVector3<T>::operator==(const TVector3& v) const
{
	return{ x == v.x && y == v.y && z == v.z };
}

template<typename T>
inline constexpr bool TVector3<T>::operator!=(const TVector3 &v) const
{
	return{ x != v.x && y != v.y && z != v.z };
}

template<typename T>
inline T TVector3<T>::operator[](const int32_t index) const
{
	assert(index >= 0 && index <= 2);
	if (index == 0)
	{
		return x;
	}
	else if (index == 1)
	{
		return y;
	}
	else
	{
		return z;
	}
}

template<typename T>
inline T& TVector3<T>::operator[](const int32_t index)
{
	assert(index >= 0 && index <= 2);
	if (index == 0)
	{
		return x;
	}
	else if (index == 1)
	{
		return y;
	}
	else
	{
		return z;
	}
}

template<typename T>
inline constexpr TVector3<T> TVector3<T>::clampSize(T min, T max) const
{
	return { clamp(x, min, max), clamp(y, min, max), clamp(z, min, max) };
}

template<typename T>
constexpr T TVector3<T>::getMax() const
{
	return max({ x, y, z });
}

template<typename T>
constexpr T TVector3<T>::getMin() const
{
	return min({ x, y, z });
}

template<typename T>
inline constexpr bool TVector3<T>::isNormalized() const
{
	return abs(T{ 1 } -lengthSquared()) < static_cast<T>(0.01);
}

template<typename T>
inline constexpr bool TVector3<T>::isZero() const
{
	return x == T{ 0 } && y == T{ 0 } && z == T{ 0 };
}

template<typename T>
constexpr T TVector3<T>::length() const
{
	return sqrt(lengthSquared());
}

template<typename T>
constexpr T TVector3<T>::lengthSquared() const
{
	return x * x + y * y + z * z;
}

template<typename T>
inline void TVector3<T>::normalize()
{
	const T vectorLength{ length() };
	if (vectorLength != T{ 0 })
	{
		x /= vectorLength;
		y /= vectorLength;
		z /= vectorLength;
	}
}

template<typename T>
inline TVector3<T> TVector3<T>::normalized() const
{
	const T vectorLength{ length() };
	if (vectorLength == T{ 0 })
	{
		return{ 0, 0, 0 };
	}

	return { x / vectorLength, y / vectorLength, z / vectorLength };
}

template<typename T>
inline constexpr TVector3<T> TVector3<T>::crossProduct(const TVector3& v1, const TVector3& v2)
{
	return{
		(v1.y * v2.z - v1.z * v2.y),
		(v1.z * v2.x - v1.x * v2.z),
		(v1.x * v2.y - v1.y * v2.x)
	};
}

template<typename T>
inline constexpr T TVector3<T>::dotProduct(const TVector3& v1, const TVector3& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template<typename T>
inline constexpr T TVector3<T>::distance(const TVector3& v1, const TVector3& v2)
{
	return (v2 - v1).length();
}

template<typename T>
inline constexpr T TVector3<T>::distanceSquared(const TVector3& v1, const TVector3& v2)
{
	return (v2 - v1).lengthSquared();
}

template<typename T>
inline constexpr TVector3<T> TVector3<T>::reflect(const TVector3& inDirection, const TVector3& normal)
{
	return normal - TVector3<T>::dotProduct(normal, inDirection) * T { 2 };
}

template<typename T>
constexpr T TVector3<T>::angleRadian(const TVector3 & v1, const TVector3 & v2)
{
	return acos(TVector3<T>::dotProduct(v1, v2) / sqrt(v1.lengthSquared() * v2.lengthSquared()));
}

template<typename T>
TVector3<T> TVector3<T>::lerp(const TVector3 & v1, const TVector3 & v2, const T t)
{

	const T s{ T{ 1 } - t };

	return 
	{
		v1.x * s + v2.x * t,
		v1.y * s + v2.y * t,
		v1.z * s + v2.z * t
	};
}

template<typename T>
inline constexpr TVector3<T> operator*(const T scale, const TVector3<T>& v)
{
	return v.operator*(scale);
}

template<typename T>
const TVector3<T> TVector3<T>::unitVector = { 1, 1, 1 };

template<typename T>
const TVector3<T> TVector3<T>::zeroVector = { 0, 0, 0 };

template class TVector3<float>;
template class TVector3<double>;
template TVector3<float> operator*(const float scale, const TVector3<float>& vector);
template TVector3<double> operator*(const double scale, const TVector3<double>& vector);

} // end of namespace sqmath
// [EOF]
