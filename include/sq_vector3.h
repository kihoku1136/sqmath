#pragma once
#include<cstdint>
namespace sqmath
{

template<typename T>
class TVector3 final
{
public:
	/**
	* @brief �f�t�H���g�R���X�g���N�^
	*/
	constexpr TVector3() = default;

	/**
	* @brief �R�s�[�R���X�g���N�^
	*/
	constexpr TVector3(const TVector3& other) = default;

	/**
	* @brief �R�s�[������Z�q
	*/
	TVector3& operator=(const TVector3& other) = default;

	/**
	* @brief ���[�u�R���X�g���N�^
	*/
	constexpr TVector3(TVector3&& other) = default;

	/**
	* @brief ���[�u������Z�q
	*/
	TVector3& operator=(TVector3&& other) = default;

	/**
	* @brief ���ׂĂ̐������ЂƂ̒l�ŏ���������R���X�g���N�^�B
	* @param[in] inValue ���ׂĂ̒l��inValue�ŏ�����
	*/
	explicit constexpr TVector3(T inValue);

	/**
	* @brief �e���������ꂼ��̒l�ŏ���������R���X�g���N�^�B
	* @param[in] inX X����
	* @param[in] inY Y����
	* @param[in] inZ Z����
	*/
	constexpr TVector3(T inX, T inY, T inZ);

	/**
	* @brief �f�X�g���N�^
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
	* @brief Vector�̒��g��clamp���܂��B
	* @param[in] min clamp����ŏ��l
	* @param[in] max clamp����ő�l
	*/
	constexpr TVector3 clampSize(T min, T max) const;

	/**
	* @brief �e�����̂Ȃ��̍ő�l���擾���܂��B
	* @return �e�����̂Ȃ��̍ő�l
	*/
	constexpr T getMax() const;

	/**
	* @brief �e�����̂Ȃ��̍ŏ��l���擾���܂��B
	* @return �e�����̂Ȃ��̍ŏ��l
	*/
	constexpr T getMin() const;

	/**
	* @brief ���K������Ă��邩�ǂ������肵�܂��B
	* @retval true ���K���ςł��B
	* @retval false ���K������Ă��܂���B
	*/
	constexpr bool isNormalized() const;

	/**
	* @brief �[���x�N�g�����ǂ����𔻒肵�܂��B
	* @retval true �[���x�N�g���ł��B
	* @retval false �[���x�N�g���ł͂���܂���B
	*/
	constexpr bool isZero() const;

	/**
	* @brief �x�N�g���̑傫�������߂܂��B
	* @return �x�N�g���̑傫��
	*/
	constexpr T length() const;

	/**
	* @brief �x�N�g���̑傫���̓������߂܂��B
	* @return �x�N�g���̑傫���̓��
	*/
	constexpr T lengthSquared() const;

	/**
	* @brief ���g�𐳋K�����܂��B���K���ł��Ȃ��ꍇ�͕ύX�͋N����܂���B
	*/
	void normalize();

	/**
	* @brief ���K�������x�N�g����Ԃ��܂��B���K���ł��Ȃ��ꍇ��Vector3(0, 0, 0)��Ԃ��܂��B
	*/
	TVector3 normalized() const;

	/**
	* @brief �O�ς��v�Z���܂��B
	* @param[in] vector1�@��ڂ̃x�N�g��
	* @param[in] vector2�@��ڂ̃x�N�g��
	* @return �O��
	*/
	static constexpr TVector3 crossProduct(const TVector3& v1, const TVector3& v2);

	/**
	* @brief�@���ς��v�Z���܂��B
	* @param[in] vector1�@��ڂ̃x�N�g��
	* @param[in] vector2�@��ڂ̃x�N�g��
	* @return ����
	*/
	static constexpr T dotProduct(const TVector3& v1, const TVector3& v2);

	/**
	* @brief ��_�Ԃ̋��������߂܂��B
	* @param[in] vector1
	* @param[in] vevtor2
	* @return ��_�Ԃ̋���
	*/
	static constexpr T distance(const TVector3& v1, const TVector3& v2);

	/**
	* @brief ��_�Ԃ̋����̓������߂܂��B
	* @param[in] vector1
	* @param[in] vevtor2
	* @return ��_�Ԃ̋����̓��
	*/
	static constexpr T distanceSquared(const TVector3& v1, const TVector3& v2);

	/**
	* @brief ���˃x�N�g�������߂܂��B
	* @param[in] inDirection ���˃x�N�g��
	* @param[in] normal �~���[����Ώۂ̃x�N�g��
	*/
	static constexpr TVector3<T> reflect(const TVector3& inDirection, const TVector3& normal);

	/**
	* @brief ��̃x�N�g���̂Ȃ��p�����߂܂�
	* @param[in] v1 �x�N�g��1
	* @param[in] v2 �x�N�g��2
	* @return ��̃x�N�g���̂Ȃ��p
	*/
	static constexpr T angleRadian(const TVector3& v1, const TVector3& v2);

	/**
	* @brief ���`�⊮
	* @param[in] v1 �x�N�g��1
	* @param[in] v2 �x�N�g��2
	* @param[in] t ��Ԃ̎���
	*/
	static TVector3 lerp(const TVector3& v1, const TVector3& v2, T t);

public:
	static const TVector3 unitVector;		///< ���ׂĂ̗v�f���P�̃x�N�g��
	static const TVector3 zeroVector;		///<�@���ׂĂ̗v�f��0�̃x�N�g��

public:
	T x{ 0 };								///< �x�N�g����X����
	T y{ 0 };								///< �x�N�g����Y����
	T z{ 0 };								///< �x�N�g����Z����
};


template<typename T>
constexpr TVector3<T> operator*(const T scale, const TVector3<T>& v);

using Vector3f = TVector3<float>;
using Vector3d = TVector3<double>;

} // end of namespace sqmath
// [EOF]
