#ifndef __TVECTOR4_HPP__
#define __TVECTOR4_HPP__

#include "MathMacro.h"
#include "MathCore.h"
#include <limits>
#include <array>

BEGIN_NAMESPACE

template<validtype T>
class TVector4
{
public:
	TVector4();
	TVector4(const T& val);
	TVector4(const T& x = T(), const T& y = T(), const T& z = T(), const T& w = T());
	TVector4(const TVector2<T>& other);
	TVector4(const TVector3<T>& other);
	TVector4(const TVector4& other);
	TVector4(TVector4&& other) noexcept;

public:
	void setX(const T& val);
	void setY(const T& val);
	void setZ(const T& val);
	void setW(const T& val);
	void set(const T& x = T(), const T& y = T(), const T& z = T(), const T& w = T());

	T x() const;
	T y() const;
	T z() const;
	T w() const;
	T& rx();
	T& ry();
	T& rz();
	T& rw();
	const T& cx() const;
	const T& cy() const;
	const T& cz() const;
	const T& cw() const;

public:
	TVector4 operator+(const TVector4& other);
	TVector4 operator-(const TVector4& other);
	TVector4 operator-();
	TVector4 operator*(const T& val);
	TVector4 operator/(const T& val);
	TVector4& operator+=(const TVector4& other);
	TVector4& operator-=(const TVector4& other);
	TVector4& operator*=(const T& val);
	TVector4& operator/=(const T& val);
	TVector4& operator=(const TVector4& other);
	TVector4& operator=(TVector4&& other) noexcept;
	bool operator==(const TVector4& other) const;
	bool operator!=(const TVector4& other) const;

	T operator*(const TVector4& other);
	T dot(const TVector4& other);

	TVector4 operator^(const TVector4& other);
	TVector4& operator^=(const TVector4& other);
	TVector4 cross(const TVector4& other);

	void fill(const T& val);
	void makeZero();
	double length();
	T squaredLength();
	void normalized();
	TVector4 makeNormalize();

	/**
	 * @brief Æë´ÎÐÔ
	 */
	void makeHomogeneous();

	template <validtype U, validtype W>
	friend TVector4<U> operator*(W val, const TVector4<U>& vec);

public:
	static const TVector4 zeroVector;
	static const TVector4 unitVector;
	static const TVector4 xAxisVector;
	static const TVector4 yAxisVector;
	static const TVector4 zAxisVector;
	static const TVector4 wAxisVector;

private:
	std::array<T, 4> m_xyzw;
};

template <validtype T>
TVector4<T>::TVector4()
{
	m_xyzw.fill(T());
}

template <validtype T>
TVector4<T>::TVector4(const T& val)
{
	m_xyzw.fill(val);
}

template <validtype T>
TVector4<T>::TVector4(const T& x, const T& y, const T& z, const T& w)
{
	m_xyzw[0] = x;
	m_xyzw[1] = y;
	m_xyzw[2] = z;
	m_xyzw[3] = w;
}

template <validtype T>
TVector4<T>::TVector4(const TVector2<T>& other)
{
	m_xyzw[0] = other.m_xy[0];
	m_xyzw[1] = other.m_xy[1];
}

template <validtype T>
TVector4<T>::TVector4(const TVector3<T>& other)
{
	m_xyzw[0] = other.m_xyz[0];
	m_xyzw[1] = other.m_xyz[1];
	m_xyzw[2] = other.m_xyz[2];
}

template <validtype T>
TVector4<T>::TVector4(const TVector4& other)
{
	m_xyzw = other.m_xyzw;
}

template <validtype T>
TVector4<T>::TVector4(TVector4&& other) noexcept
{
	m_xyzw = other.m_xyzw;
	other = zeroVector;
}

template <validtype T>
void TVector4<T>::setX(const T& val)
{
	m_xyzw[0] = val;
}

template <validtype T>
void TVector4<T>::setY(const T& val)
{
	m_xyzw[1] = val;
}

template <validtype T>
void TVector4<T>::setZ(const T& val)
{
	m_xyzw[2] = val;
}

template <validtype T>
void TVector4<T>::setW(const T& val)
{
	m_xyzw[3] = val;
}

template <validtype T>
void TVector4<T>::set(const T& x, const T& y, const T& z, const T& w)
{
	m_xyzw[0] = x;
	m_xyzw[1] = y;
	m_xyzw[2] = z;
	m_xyzw[3] = w;
}

template <validtype T>
T TVector4<T>::x() const
{
	return m_xyzw[0];
}

template <validtype T>
T TVector4<T>::y() const
{
	return m_xyzw[1];
}

template <validtype T>
T TVector4<T>::z() const
{
	return m_xyzw[2];
}

template <validtype T>
T TVector4<T>::w() const
{
	return m_xyzw[3];
}

template <validtype T>
T& TVector4<T>::rx()
{
	return m_xyzw[0];
}

template <validtype T>
T& TVector4<T>::ry()
{
	return m_xyzw[1];
}

template <validtype T>
T& TVector4<T>::rz()
{
	return m_xyzw[2];
}

template <validtype T>
T& TVector4<T>::rw()
{
	return m_xyzw[3];
}

template <validtype T>
const T& TVector4<T>::cx() const
{
	return m_xyzw[0];
}

template <validtype T>
const T& TVector4<T>::cy() const
{
	return m_xyzw[1];
}

template <validtype T>
const T& TVector4<T>::cz() const
{
	return m_xyzw[2];
}

template <validtype T>
const T& TVector4<T>::cw() const
{
	return m_xyzw[3];
}

template <validtype T>
TVector4<T> TVector4<T>::operator+(const TVector4& other)
{
	return std::move(TVector4(
		m_xyzw[0] + other.m_xyzw[0],
		m_xyzw[1] + other.m_xyzw[1],
		m_xyzw[2] + other.m_xyzw[2],
		m_xyzw[3] + other.m_xyzw[3]
	));
}

template <validtype T>
TVector4<T> TVector4<T>::operator-(const TVector4& other)
{
	return std::move(TVector4(
		m_xyzw[0] - other.m_xyzw[0],
		m_xyzw[1] - other.m_xyzw[1],
		m_xyzw[2] - other.m_xyzw[2],
		m_xyzw[3] - other.m_xyzw[3]
	));
}

template <validtype T>
TVector4<T> TVector4<T>::operator-()
{
	return std::move(-m_xyzw[0], -m_xyzw[1], -m_xyzw[2], -m_xyzw[3]);
}

template <validtype T>
TVector4<T> TVector4<T>::operator*(const T& val)
{
	return std::move(TVector4(
		m_xyzw[0] * val,
		m_xyzw[1] * val,
		m_xyzw[2] * val,
		m_xyzw[3] * val
	));
}

template <validtype T>
TVector4<T> TVector4<T>::operator/(const T& val)
{
	if (T() == val)
	{
		// std::cerr << "Error: Division by zero" << std::endl;
		return std::move(TVector4(std::numeric_limits<T>::quiet_NaN()));
	}

	return std::move(TVector4(
		m_xyzw[0] / val,
		m_xyzw[1] / val,
		m_xyzw[2] / val,
		m_xyzw[3] / val
	));
}

template <validtype T>
TVector4<T>& TVector4<T>::operator+=(const TVector4& other)
{
	for (int i(0); i < m_xyzw.size(); ++i)
	{
		m_xyzw[i] += other.m_xyzw[i];
	}
	return *this;
}

template <validtype T>
TVector4<T>& TVector4<T>::operator-=(const TVector4& other)
{
	for (int i(0); i < m_xyzw.size(); ++i)
	{
		m_xyzw[i] -= other.m_xyzw[i];
	}
	return *this;
}

template <validtype T>
TVector4<T>& TVector4<T>::operator*=(const T& val)
{
	for (int i(0); i < m_xyzw.size(); ++i)
	{
		m_xyzw[i] *= val;
	}
	return *this;
}

template <validtype T>
TVector4<T>& TVector4<T>::operator/=(const T& val)
{
	if (T() == val)
	{
		// std::cerr << "Error: Division by zero" << std::endl;
		return std::move(TVector4(std::numeric_limits<T>::quiet_NaN()));
	}

	for (int i(0); i < m_xyzw.size(); ++i)
	{
		m_xyzw[i] /= val;
	}
	return *this;
}

template <validtype T>
TVector4<T>& TVector4<T>::operator=(const TVector4& other)
{
	if (*this != &other)
	{
		m_xyzw = other.m_xyzw;
	}

	return *this;
}

template <validtype T>
TVector4<T>& TVector4<T>::operator=(TVector4&& other) noexcept
{
	if (*this != &other)
	{
		m_xyzw = other.m_xyzw;
		other = zeroVector;
	}
	
	return *this;
}

template <validtype T>
bool TVector4<T>::operator==(const TVector4& other) const
{
	return (m_xyzw == other.m_xyzw);
}

template <validtype T>
bool TVector4<T>::operator!=(const TVector4& other) const
{
	return (m_xyzw != other.m_xyzw);
}

template <validtype T>
T TVector4<T>::operator*(const TVector4& other)
{
	return m_xyzw[0] * m_xyzw[0] + m_xyzw[1] * m_xyzw[1] + m_xyzw[2] * m_xyzw[2] + m_xyzw[3] * m_xyzw[3];
}

template <validtype T>
T TVector4<T>::dot(const TVector4& other)
{
	return *this * other;
}

template <validtype T>
TVector4<T> TVector4<T>::operator^(const TVector4& other)
{
	return TVector4(
		m_xyzw[1] * other.m_xyzw[2] - m_xyzw[2] * other.m_xyzw[1],
		m_xyzw[2] * other.m_xyzw[0] - m_xyzw[0] * other.m_xyzw[2],
		m_xyzw[0] * other.m_xyzw[1] - m_xyzw[1] * other.m_xyzw[0],
		T()
	);
}

template <validtype T>
TVector4<T>& TVector4<T>::operator^=(const TVector4& other)
{
	*this = *this ^ other;
	return *this;
}

template <validtype T>
TVector4<T> TVector4<T>::cross(const TVector4& other)
{
	return std::move(*this ^ other);
}

template <validtype T>
void TVector4<T>::fill(const T& val)
{
	m_xyzw.fill(val);
}

template <validtype T>
void TVector4<T>::makeZero()
{
	m_xyzw.fill(T());
}

template <validtype T>
double TVector4<T>::length()
{
	return std::sqrt(squaredLength());
}

template <validtype T>
T TVector4<T>::squaredLength()
{
	return m_xyzw[0] * m_xyzw[0] + m_xyzw[1] * m_xyzw[1] + m_xyzw[2] * m_xyzw[2] + m_xyzw[3] * m_xyzw[3];
}

template <validtype T>
void TVector4<T>::normalized()
{
	*this = makeNormalize();
}

template <validtype T>
TVector4<T> TVector4<T>::makeNormalize()
{
	double len = length();
	if (std::abs(len) > 0.0)
	{
		return *this / length();
	}
	return {};
}

template <validtype T>
void TVector4<T>::makeHomogeneous()
{
	if (m_xyzw[3] != T())
	{
		*this /= m_xyzw[3];
	}
}

template <validtype U, validtype W>
TVector4<U> operator*(W val, const TVector4<U>& vec)
{
	return vec * val;
}

END_NAMESPACE

#endif // !__TVECTOR4_HPP__
