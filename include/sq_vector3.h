#pragma once
#include<cstdint>
namespace sqmath
{

template<typename T>
class TVector3 final
{
public:
	/**
	* @brief デフォルトコンストラクタ
	*/
	constexpr TVector3() = default;

	/**
	* @brief コピーコンストラクタ
	*/
	constexpr TVector3(const TVector3& other) = default;

	/**
	* @brief コピー代入演算子
	*/
	TVector3& operator=(const TVector3& other) = default;

	/**
	* @brief ムーブコンストラクタ
	*/
	constexpr TVector3(TVector3&& other) = default;

	/**
	* @brief ムーブ代入演算子
	*/
	TVector3& operator=(TVector3&& other) = default;

	/**
	* @brief すべての成分をひとつの値で初期化するコンストラクタ。
	* @param[in] inValue すべての値をinValueで初期化
	*/
	explicit constexpr TVector3(T inValue);

	/**
	* @brief 各成分をそれぞれの値で初期化するコンストラクタ。
	* @param[in] inX X成分
	* @param[in] inY Y成分
	* @param[in] inZ Z成分
	*/
	constexpr TVector3(T inX, T inY, T inZ);

	/**
	* @brief デストラクタ
	*/
	~TVector3() = default;

	/**
	* @brief operators
	*/
	inline constexpr TVector3 operator+(const TVector3& v) const;
	inline constexpr TVector3 operator+(T bias) const;
	inline TVector3 operator+=(const TVector3& v);
	inline constexpr TVector3 operator-(const TVector3& v) const;
	inline constexpr TVector3 operator-(T bias) const;
	inline constexpr TVector3 operator-() const;
	inline TVector3 operator-=(const TVector3& v);
	inline constexpr TVector3 operator*(const TVector3& v) const;
	inline constexpr TVector3 operator*(T scale) const;
	inline TVector3 operator*=(const TVector3& v);
	inline constexpr TVector3 operator/(const TVector3& v) const;
	inline constexpr TVector3 operator/(T scale) const;
	inline TVector3 operator/=(const TVector3& v);
	inline constexpr bool operator==(const TVector3& v) const;
	inline constexpr bool operator!=(const TVector3& v) const;
	inline T operator[](int32_t index) const;
	inline T& operator[](int32_t index);

	/**
	* @brief Vectorの中身をclampします。
	* @param[in] min clampする最小値
	* @param[in] max clampする最大値
	*/
	constexpr TVector3 clampSize(T min, T max) const;

	/**
	* @brief 各成分のなかの最大値を取得します。
	* @return 各成分のなかの最大値
	*/
	constexpr T getMax() const;

	/**
	* @brief 各成分のなかの最小値を取得します。
	* @return 各成分のなかの最小値
	*/
	constexpr T getMin() const;

	/**
	* @brief 正規化されているかどうか判定します。
	* @retval true 正規化済です。
	* @retval false 正規化されていません。
	*/
	constexpr bool isNormalized() const;

	/**
	* @brief ゼロベクトルかどうかを判定します。
	* @retval true ゼロベクトルです。
	* @retval false ゼロベクトルではありません。
	*/
	constexpr bool isZero() const;

	/**
	* @brief ベクトルの大きさを求めます。
	* @return ベクトルの大きさ
	*/
	constexpr T length() const;

	/**
	* @brief ベクトルの大きさの二乗を求めます。
	* @return ベクトルの大きさの二乗
	*/
	constexpr T lengthSquared() const;

	/**
	* @brief 自身を正規化します。正規化できない場合は変更は起こりません。
	*/
	void normalize();

	/**
	* @brief 正規化したベクトルを返します。正規化できない場合はVector3(0, 0, 0)を返します。
	*/
	TVector3 normalized() const;

	/**
	* @brief 外積を計算します。
	* @param[in] vector1　一つ目のベクトル
	* @param[in] vector2　二つ目のベクトル
	* @return 外積
	*/
	static constexpr TVector3 crossProduct(const TVector3& v1, const TVector3& v2);

	/**
	* @brief　内積を計算します。
	* @param[in] vector1　一つ目のベクトル
	* @param[in] vector2　二つ目のベクトル
	* @return 内積
	*/
	static constexpr T dotProduct(const TVector3& v1, const TVector3& v2);

	/**
	* @brief 二点間の距離を求めます。
	* @param[in] vector1
	* @param[in] vevtor2
	* @return 二点間の距離
	*/
	static constexpr T distance(const TVector3& v1, const TVector3& v2);

	/**
	* @brief 二点間の距離の二乗を求めます。
	* @param[in] vector1
	* @param[in] vevtor2
	* @return 二点間の距離の二乗
	*/
	static constexpr T distanceSquared(const TVector3& v1, const TVector3& v2);

	/**
	* @brief 反射ベクトルを求めます。
	* @param[in] inDirection 入射ベクトル
	* @param[in] normal ミラーする対象のベクトル
	*/
	static constexpr TVector3<T> reflect(const TVector3& inDirection, const TVector3& normal);

	/**
	* @brief 二つのベクトルのなす角を求めます
	* @param[in] v1 ベクトル1
	* @param[in] v2 ベクトル2
	* @return 二つのベクトルのなす角
	*/
	static constexpr T angleRadian(const TVector3& v1, const TVector3& v2);

	/**
	* @brief 線形補完
	* @param[in] v1 ベクトル1
	* @param[in] v2 ベクトル2
	* @param[in] t 補間の時間
	*/
	static TVector3 lerp(const TVector3& v1, const TVector3& v2, T t);

public:
	static const TVector3 unitVector;		///< すべての要素が１のベクトル
	static const TVector3 zeroVector;		///<　すべての要素が0のベクトル

public:
	T x{ 0 };								///< ベクトルのX成分
	T y{ 0 };								///< ベクトルのY成分
	T z{ 0 };								///< ベクトルのZ成分
};


template<typename T>
constexpr TVector3<T> operator*(const T scale, const TVector3<T>& v);

using Vector3f = TVector3<float>;
using Vector3d = TVector3<double>;

} // end of namespace sqmath
// [EOF]
