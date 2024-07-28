#ifndef __TVECTOR3_HPP__
#define __TVECTOR3_HPP__

#include "MathMacro.h"
#include "MathCore.h"
#include <array>

BEGIN_NAMESPACE

template<validtype T>
class TVector3
{
public:
	TVector3();
	TVector3(const T& val);
	TVector3(const T& x, const T& y, const T& z);
	TVector3(const TVector3& other);
	TVector3(TVector3&& other) noexcept;

	~TVector3() = default;

	void setX(const T& x);
	void setY(const T& y);
	void setZ(const T& z);
	void setXYZ(const T& x, const T& y, const T& z);

	T x() const;
	T y() const;
	T z() const;
	T& rx();
	T& ry();
	T& rz();
	const T cx() const;
	const T cy() const;
	const T cz() const;
public:
	TVector3 operator+(const TVector3& other);
	TVector3 operator-(const TVector3& other);
	TVector3 operator-();
	TVector3 operator*(const T& val);
	TVector3 operator/(const T& val);
	TVector3& operator=(const TVector3& other);
	TVector3& operator=(TVector3&& other) noexcept;
	TVector3& operator+=(const TVector3& other);
	TVector3& operator-=(const TVector3& other);
	TVector3& operator*=(const T& val);
	TVector3& operator/=(const T& val);

	bool operator==(const TVector3& other) const;
	bool operator!=(const TVector3& other) const;

	T operator[](const int index) const;
	T& operator[](const int index);

	T operator*(const TVector3& other);
	T dot(const TVector3& other);

	TVector3 operator^(const TVector3& other);
	TVector3& operator^=(const TVector3& other);
	TVector3 cross(const TVector3& other);

	void makeZero();

	double length();

	T squaredLength();

	void normalized();

	double distanceTo(const TVector3& vec);

	template <validtype U, validtype W>
	friend TVector3<U> operator*(W val, const TVector3<U>& vec);

public:
	static const TVector3 zeroVector;
	static const TVector3 unitVector;
	static const TVector3 xAxisVector;
	static const TVector3 yAxisVector;
	static const TVector3 zAxisVector;

private:
	std::array<T, 3> m_xyz;
};

template<validtype T>
TVector3<T>::TVector3()
{
	m_xyz[0] = m_xyz[1] = m_xyz[2] = T();
}

template <validtype T>
TVector3<T>::TVector3(const T& val)
{
	m_xyz[0] = m_xyz[1] = m_xyz[2] = val;
}

template<validtype T>
TVector3<T>::TVector3(const T& x, const T& y, const T& z)
{
	m_xyz[0] = x;
	m_xyz[1] = y;
	m_xyz[2] = z;
}

template<validtype T>
TVector3<T>::TVector3(const TVector3& other)
{
	for (int i(0); i < m_xyz.size(); ++i)
	{
		m_xyz[i] = other.m_xyz[i];
	}
}

template<validtype T>
TVector3<T>::TVector3(TVector3&& other) noexcept
{
	for (int i(0); i < m_xyz.size(); ++i)
	{
		m_xyz[i] = other.m_xyz[i];
	}
	other = zeroVector;
}

template <validtype T>
void TVector3<T>::setX(const T& x)
{
	m_xyz[0] = x;
}

template <validtype T>
void TVector3<T>::setY(const T& y)
{
	m_xyz[1] = y;
}

template <validtype T>
void TVector3<T>::setZ(const T& z)
{
	m_xyz[2] = z;
}

template <validtype T>
void TVector3<T>::setXYZ(const T& x, const T& y, const T& z)
{
	m_xyz[0] = x;
	m_xyz[1] = y;
	m_xyz[2] = z;
}

template <validtype T>
T TVector3<T>::x() const
{
	return m_xyz[0];
}

template <validtype T>
T TVector3<T>::y() const
{
	return m_xyz[1];
}

template <validtype T>
T TVector3<T>::z() const
{
	return m_xyz[2];
}

template <validtype T>
T& TVector3<T>::rx()
{
	return m_xyz[0];
}

template <validtype T>
T& TVector3<T>::ry()
{
	return m_xyz[1];
}

template <validtype T>
T& TVector3<T>::rz()
{
	return m_xyz[2];
}

template <validtype T>
const T TVector3<T>::cx() const
{
	return m_xyz[0];
}

template <validtype T>
const T TVector3<T>::cy() const
{
	return m_xyz[1];
}

template <validtype T>
const T TVector3<T>::cz() const
{
	return m_xyz[2];
}

template <validtype T>
TVector3<T> TVector3<T>::operator+(const TVector3& other)
{
	return std::move(TVector3(m_xyz[0] + other.m_xyz[0], m_xyz[1] + other.m_xyz[1], m_xyz[2] + other.m_xyz[2]));
}

template <validtype T>
TVector3<T> TVector3<T>::operator-(const TVector3& other)
{
	return std::move(TVector3(m_xyz[0] - other.m_xyz[0]), m_xyz[1] - other.m_xyz[1], m_xyz[2] - other.m_xyz[2]);
}

template <validtype T>
TVector3<T> TVector3<T>::operator-()
{
	return std::move(TVector3(-m_xyz[0], -m_xyz[1], -m_xyz[2]));
}

template <validtype T>
TVector3<T> TVector3<T>::operator*(const T& val)
{
	return std::move(TVector3(m_xyz[0] * val, m_xyz[1] * val, m_xyz[2] * val));
}

template <validtype T>
TVector3<T> TVector3<T>::operator/(const T& val)
{
	if (T() == val)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return std::move(TVector3(std::numeric_limits<T>::quiet_NaN()));
	}

	return std::move(TVector3(m_xyz[0] / val, m_xyz[1] / val, m_xyz[2] / val));
}

template <validtype T>
TVector3<T>& TVector3<T>::operator=(const TVector3& other)
{
	if (*this == &other)
	{
		return *this;
	}

	for (int i(0); i < m_xyz.size(); ++i)
	{
		m_xyz[i] = other.m_xyz[i];
	}

	other = zeroVector;
	return *this;
}

template <validtype T>
TVector3<T>& TVector3<T>::operator=(TVector3&& other) noexcept
{
	if (*this == other)
	{
		return *this;
	}

	for (int i(0); i < m_xyz.size(); ++i)
	{
		m_xyz[i] = other.m_xyz[i];
	}

	other = zeroVector;
	return *this;
}

template <validtype T>
TVector3<T>& TVector3<T>::operator+=(const TVector3& other)
{
	for (int i(0); i < m_xyz.size(); ++i)
	{
		m_xyz[i] += other.m_xyz[i];
	}

	return *this;
}

template <validtype T>
TVector3<T>& TVector3<T>::operator-=(const TVector3& other)
{
	for (int i(0); i < m_xyz.size(); ++i)
	{
		m_xyz[i] -= other.m_xyz[i];
	}

	return *this;
}

template <validtype T>
TVector3<T>& TVector3<T>::operator*=(const T& val)
{
	for (int i(0); i < m_xyz.size(); ++i)
	{
		m_xyz[i] *= val;
	}

	return *this;
}

template <validtype T>
TVector3<T>& TVector3<T>::operator/=(const T& val)
{
	if (T() == val)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		*this = TVector3(std::numeric_limits<T>::quiet_NaN());
		return *this;
	}

	for (int i(0); i < m_xyz.size(); ++i)
	{
		m_xyz[i] /= val;
	}

	return *this;
}

template <validtype T>
bool TVector3<T>::operator==(const TVector3& other) const
{
	bool isEqual = true;
	for (int i(0); i < m_xyz.size(); ++i)
	{
		isEqual = (m_xyz[i] == other.m_xyz[i]);
	}
	return isEqual;
}

template <validtype T>
bool TVector3<T>::operator!=(const TVector3& other) const
{
	return !(*this == other);
}

template <validtype T>
T TVector3<T>::operator[](const int index) const
{
	return m_xyz[index];
}

template <validtype T>
T& TVector3<T>::operator[](const int index)
{
	return m_xyz[index];
}

template <validtype T>
T TVector3<T>::operator*(const TVector3& other)
{
	return m_xyz[0] * other.m_xyz[0] + m_xyz[1] * other.m_xyz[1] + m_xyz[2] * other.m_xyz[2];
}

template <validtype T>
T TVector3<T>::dot(const TVector3& other)
{
	return *this * other;
}

template <validtype T>
TVector3<T> TVector3<T>::operator^(const TVector3& other)
{
	return std::move(TVector3(
		m_xyz[1] * other.m_xyz[2] - m_xyz[2] * other.m_xyz[1],
		m_xyz[0] * other.m_xyz[2] - m_xyz[2] * other.m_xyz[0],
		m_xyz[0] * other.m_xyz[1] - m_xyz[1] * other.m_xyz[0]
	));
}

template <validtype T>
TVector3<T>& TVector3<T>::operator^=(const TVector3& other)
{
	*this = *this ^ other;
	return *this;
}

template <validtype T>
TVector3<T> TVector3<T>::cross(const TVector3& other)
{
	return *this ^ other;
}

template <validtype T>
void TVector3<T>::makeZero()
{
	*this = zeroVector;
}

template <validtype T>
double TVector3<T>::length()
{
	return std::sqrt(squaredLength());
}

template <validtype T>
T TVector3<T>::squaredLength()
{
	return std::pow(m_xyz[0], 2) + std::pow(m_xyz[1], 2) + std::pow(m_xyz[2], 2);
}

template <validtype T>
void TVector3<T>::normalized()
{
	double length = length();
	if (length > 0)
	{
		double reciprocal = 1.0 / length();
		*this *= reciprocal;
	}
}

template <validtype T>
double TVector3<T>::distanceTo(const TVector3& vec)
{
	TVector3 result(vec.m_xyz[0] - m_xyz[0], vec.m_xyz[1] - m_xyz[1], vec.m_xyz[2] - m_xyz[2]);
	return result.length();
}

END_NAMESPACE
#endif
