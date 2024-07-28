#ifndef __MATH_HEADER_H__
#define __MATH_HEADER_H__

#include "vector/TVector2.hpp"
#include "vector/TVector3.hpp"

BEGIN_NAMESPACE

// 类型定义
using Vector2i = TVector2<int>;
using Vector2f = TVector2<float>;
using Vector2d = TVector2<double>;
using Vector3i = TVector3<int>;
using Vector3f = TVector3<float>;
using Vector3d = TVector3<double>;

// 全局变量
template<> const Vector2i Vector2i::zeroVector(0, 0);
template<> const Vector2f Vector2f::zeroVector(0.f, 0.f);
template<> const Vector2d Vector2d::zeroVector(0.0, 0.0);
template<> const Vector2i Vector2i::unitVector(1, 1);
template<> const Vector2f Vector2f::unitVector(1.f, 1.f);
template<> const Vector2d Vector2d::unitVector(1.0, 1.0);
template<> const Vector2i Vector2i::xAxisVector(1, 0);
template<> const Vector2f Vector2f::xAxisVector(1.f, 0.f);
template<> const Vector2d Vector2d::xAxisVector(1.0, 0.0);
template<> const Vector2i Vector2i::yAxisVector(0, 1);
template<> const Vector2f Vector2f::yAxisVector(0.f, 1.f);
template<> const Vector2d Vector2d::yAxisVector(0.0, 1.0);

template<> const Vector3i Vector3i::zeroVector(0, 0, 0);
template<> const Vector3f Vector3f::zeroVector(0.f, 0.f, 0.f);
template<> const Vector3d Vector3d::zeroVector(0.0, 0.0, 0.0);
template<> const Vector3i Vector3i::unitVector(1, 1, 1);
template<> const Vector3f Vector3f::unitVector(1.f, 1.f, 1.f);
template<> const Vector3d Vector3d::unitVector(1.0, 1.0, 1.0);
template<> const Vector3i Vector3i::xAxisVector(1, 0, 0);
template<> const Vector3f Vector3f::xAxisVector(1.f, 0.f, 0.f);
template<> const Vector3d Vector3d::xAxisVector(1.0, 0.0, 0.0);
template<> const Vector3i Vector3i::yAxisVector(0, 1, 0);
template<> const Vector3f Vector3f::yAxisVector(0.f, 1.f, 0.f);
template<> const Vector3d Vector3d::yAxisVector(0.0, 1.0, 0.0);
template<> const Vector3i Vector3i::zAxisVector(0, 0, 1);
template<> const Vector3f Vector3f::zAxisVector(0.f, 0.f, 1.f);
template<> const Vector3d Vector3d::zAxisVector(0.0, 0.0, 1.0);

END_NAMESPACE

#endif