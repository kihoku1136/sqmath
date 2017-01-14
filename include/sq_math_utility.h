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
* @brief aとbを線形補完します
* @param[in] a 開始
* @param[in] b 終了
* @param[in] t 補間の割合
*/
template<typename T>
T lerp(T a, T b, T t)
{
	return a * (T{ 1 } - t) + b * t;
}

/**
* @brief 値を範囲内に設定します
* @param[in] inValue 対象とする値
* @param[in] min 丸め込む最少値
* @param[in] max 丸め込む最大値
*/
template<typename T>
T clamp(T inValue, T min, T max)
{
	return (inValue < min) ? min : (inValue < max) ? inValue : max;
}

/**
* @brief 度数法から弧度法へ単位変換します
* @param[in] degree 角度（度）
* @return ラジアン(rd)
*/
template<typename T>
T degreeToRadian(T degree)
{
	return degree * pi<T>() / T{ 180 };
}

/**
* @brief 弧度法から度数法へ単位変換します
* @param[in] radian ラジアン(rd)
* @return 角度（度）
*/
template<typename T>
T radianToDegree(T radian)
{
	return  radian * T{ 180 } / pi<T>();
}
} // end of namespace sqmath
// [EOF]
