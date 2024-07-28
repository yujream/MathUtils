#ifndef __TVECTOR2_HPP__
#define __TVECTOR2_HPP__

#include "MathMacro.h"
#include "MathCore.h"
#include <array>
#include <iostream>

BEGIN_NAMESPACE

template <validtype T>
class TVector2
{
public:
	TVector2();
	TVector2(const T& val);
	TVector2(const T& x, const T& y);
	TVector2(const TVector2& other);
	TVector2(TVector2&& other) noexcept;

	~TVector2() = default;
public:
	TVector2 operator+(const TVector2& other);
	TVector2 operator-(const TVector2& other);
	TVector2 operator-();
	TVector2 operator*(const T& val);
	TVector2 operator/(const T& val);
	TVector2& operator=(const TVector2& other);
	TVector2& operator=(TVector2&& other) noexcept;
	TVector2& operator+=(const TVector2& other);
	TVector2& operator-=(const TVector2& other);
	TVector2& operator*=(const T& val);
	TVector2& operator/=(const T& val);

	bool operator==(const TVector2& other) const;
	bool operator!=(const TVector2& other) const;

	T operator[](const int index) const;
	T& operator[](const int index);

	/**
	 * @brief 向量点乘
	 * @param other 另一个向量
	 * @return 点乘结果
	 */
	T operator*(const TVector2& other);

	/**
	 * @brief 向量点乘
	 * @param other 另一个向量
	 * @return 点乘结果
	 */
	T dot(const TVector2& other);

	/**
	 * @brief 向量叉乘
	 * @param other 另一个向量
	 * @return 叉乘结果
	 */
	T operator^(const TVector2& other);

	/**
	 * @brief 向量叉乘
	 * @param other 另一个向量
	 * @return 叉乘结果
	 */
	T cross(const TVector2& other);

	/**
	 * @brief 求向量长度的平方
	 * @return 向量长度的平方
	 */
	T squaredLength();

	/**
	 * @brief 计算向量的长度（模）
	 * @return 向量长度
	 */
	double length();

	/**
	 * @brief 计算两个向量的距离
	 * @param vec 另一个向量
	 * @return 返回两个向量的距离
	 */
	double distanceTo(const TVector2& vec);

	/**
	 * @brief 向量归一化
	 */
	void normalized();

	/**
	 * @brief 向量置 0
	 */
	void makeZero();

	template <validtype U, validtype W>
	friend TVector2<U> operator*(W val, const TVector2<U>& vec);

public:
	static const TVector2 zeroVector;
	static const TVector2 unitVector;
	static const TVector2 xAxisVector;
	static const TVector2 yAxisVector;
public:
	inline void setX(const T& x)
	{
		m_xy[0] = x;
	}

	inline void setY(const T& y)
	{
		m_xy[1] = y;
	}

	inline void setXY(const T& x, const T& y)
	{
		m_xy[0] = x;
		m_xy[1] = y;
	}

	inline T x() const
	{
		return m_xy[0];
	}

	inline T y() const
	{
		return m_xy[1];
	}

	inline T& rx()
	{
		return m_xy[0];
	}

	inline T& ry()
	{
		return m_xy[1];
	}

	inline const T& cx() const
	{
		return m_xy[0];
	}

	inline const T& cy() const
	{
		return m_xy[1];
	}

private:
	std::array<T, 2> m_xy;
};

template <validtype T>
TVector2<T>::TVector2()
{
	m_xy[0] = m_xy[1] = T();
}

template <validtype T>
TVector2<T>::TVector2(const T& val)
{
	m_xy[0] = m_xy[1] = val;
}

template<validtype T>
TVector2<T>::TVector2(const T& x, const T& y)
{
	m_xy[0] = x;
	m_xy[1] = y;
}

template<validtype T>
TVector2<T>::TVector2(const TVector2& other)
{
	for (int i(0); i < m_xy.size(); ++i)
	{
		m_xy[i] = other.m_xy[i];
	}
}

template <validtype T>
TVector2<T>::TVector2(TVector2&& other) noexcept
{
	for (int i(0); i < m_xy.size(); ++i)
	{
		m_xy[i] = other.m_xy[i];
	}

	other = zeroVector;
}

template <validtype T>
TVector2<T> TVector2<T>::operator+(const TVector2& other)
{
	return std::move(TVector2(m_xy[0] + other.m_xy[0], m_xy[1] + other.m_xy[1]));
}

template <validtype T>
TVector2<T> TVector2<T>::operator-(const TVector2& other)
{
	return std::move(TVector2(m_xy[0] - other.m_xy[0], m_xy[1] - other.m_xy[1]));
}

template <validtype T>
TVector2<T> TVector2<T>::operator-()
{
	return std::move(TVector2(-m_xy[0], -m_xy[1]));
}

template <validtype T>
TVector2<T> TVector2<T>::operator*(const T& val)
{
	return std::move(TVector2(m_xy[0] * val, m_xy[1] * val));
}

template <validtype T>
TVector2<T> TVector2<T>::operator/(const T& val)
{
	if (T() == val)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return std::move(TVector2(std::numeric_limits<T>::quiet_NaN()));
	}
	return std::move(TVector2(m_xy[0] / val, m_xy[1] / val));
}

template <validtype T>
TVector2<T>& TVector2<T>::operator=(const TVector2& other)
{
	if (this == &other)
	{
		return *this;
	}

	for (int i(0); i < m_xy.size(); ++i)
	{
		m_xy[i] = other.m_xy[i];
	}

	return *this;
}

template <validtype T>
TVector2<T>& TVector2<T>::operator=(TVector2&& other) noexcept
{
	if (this == &other)
	{
		return *this;
	}

	for (int i(0); i < m_xy.size(); ++i)
	{
		m_xy[i] = other.m_xy[i];
	}

	other = zeroVector;
	return *this;
}

template <validtype T>
TVector2<T>& TVector2<T>::operator+=(const TVector2& other)
{
	for (int i(0); i < m_xy.size(); ++i)
	{
		m_xy[i] += other.m_xy[i];
	}

	return *this;
}

template <validtype T>
TVector2<T>& TVector2<T>::operator-=(const TVector2& other)
{
	for (int i(0); i < m_xy.size(); ++i)
	{
		m_xy[i] -= other.m_xy[i];
	}

	return *this;
}

template <validtype T>
TVector2<T>& TVector2<T>::operator*=(const T& val)
{
	for (int i(0); i < m_xy.size(); ++i)
	{
		m_xy[i] *= val;
	}

	return *this;
}

template <validtype T>
TVector2<T>& TVector2<T>::operator/=(const T& val)
{
	if (T() == val)
	{
		std::cerr << "Error: Division by zero" << std::endl;

		*this = TVector2(std::numeric_limits<T>::quiet_NaN());
		return *this;
	}

	for (int i(0); i < m_xy.size(); ++i)
	{
		m_xy[i] /= val;
	}

	return *this;
}

template <validtype T>
bool TVector2<T>::operator==(const TVector2& other) const
{
	bool isEqual = true;
	for (int i(0); i < m_xy.size(); ++i)
	{
		isEqual = (m_xy[i] == other.m_xy[i]);
	}

	return isEqual;
}

template <validtype T>
bool TVector2<T>::operator!=(const TVector2& other) const
{
	return !(*this == other);
}

template <validtype T>
T TVector2<T>::operator[](const int index) const
{
	if (index < 0 || index > 1)
	{
		std::cerr << "Error: illegal index" << std::endl;
		return std::numeric_limits<T>::quiet_NaN();
	}

	return m_xy[index];
}

template <validtype T>
T& TVector2<T>::operator[](const int index)
{
	if (index < 0 || index > 1)
	{
		std::cerr << "Error: illegal index" << std::endl;
		return std::numeric_limits<T>::quiet_NaN();
	}

	return m_xy[index];
}

template <validtype T>
T TVector2<T>::operator*(const TVector2& other)
{
	return m_xy[0] * other.m_xy[0] + m_xy[1] * other.m_xy[1];
}

template <validtype T>
T TVector2<T>::dot(const TVector2& other)
{
	return *this * other;
}

template <validtype T>
T TVector2<T>::operator^(const TVector2& other)
{
	return m_xy[0] * other.m_xy[1] - m_xy[1] * other.m_xy[0];
}

template <validtype T>
T TVector2<T>::cross(const TVector2& other)
{
	return *this ^ other;
}

template <validtype T>
T TVector2<T>::squaredLength()
{
	return std::pow(m_xy[0], 2) + std::pow(m_xy[1], 2);
}

template <validtype T>
double TVector2<T>::length()
{
	return std::sqrt(squaredLength());
}

template <validtype T>
double TVector2<T>::distanceTo(const TVector2& vec)
{
	TVector2 result = vec - *this;
	return result.length();
}

template <validtype T>
void TVector2<T>::normalized()
{
	double reciprocal = 1.0 / this->length();
	m_xy[0] *= reciprocal;
	m_xy[1] *= reciprocal;
}

template <validtype T>
void TVector2<T>::makeZero()
{
	*this = zeroVector;
}

template <validtype U, validtype W>
TVector2<U> operator*(W val, const TVector2<U>& vec)
{
	return TVector2D<U>(val * vec.m_xy[0], val * vec.m_xy[1]);
}

END_NAMESPACE

#endif // !__TVECTOR_H__
