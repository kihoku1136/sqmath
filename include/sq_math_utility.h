#pragma once
#include <sq_constant.h>
#include <cmath>
#include <algorithm>
namespace sqmath
{

using std::abs;
using std::min;
using std::max;
using std::floor;
using std::ceil;
using std::trunc;

using std::log;
using std::exp;
using std::sqrt;
using std::pow;

using std::sin;
using std::cos;
using std::tan;

using std::asin;
using std::acos;
using std::atan;
using std::atan2;


/**
* @brief a��b����`�⊮���܂�
* @param[in] a �J�n
* @param[in] b �I��
* @param[in] t ��Ԃ̊���
*/
template<typename T>
T lerp(T a, T b, T t)
{
	return a * (T{ 1 } - t) + b * t;
}

/**
* @brief �l��͈͓��ɐݒ肵�܂�
* @param[in] inValue �ΏۂƂ���l
* @param[in] min �ۂߍ��ލŏ��l
* @param[in] max �ۂߍ��ލő�l
*/
template<typename T>
T clamp(T inValue, T min, T max)
{
	return (inValue < min) ? min : (inValue < max) ? inValue : max;
}

/**
* @brief �x���@����ʓx�@�֒P�ʕϊ����܂�
* @param[in] degree �p�x�i�x�j
* @return ���W�A��(rd)
*/
template<typename T>
T degreeToRadian(T degree)
{
	return degree * pi<T>() / T{ 180 };
}

/**
* @brief �ʓx�@����x���@�֒P�ʕϊ����܂�
* @param[in] radian ���W�A��(rd)
* @return �p�x�i�x�j
*/
template<typename T>
T radianToDegree(T radian)
{
	return  radian * T{ 180 } / pi<T>();
}
} // end of namespace sqmath
// [EOF]
