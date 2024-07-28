#ifndef __MATH_CORE_H__
#define __MATH_CORE_H__

BEGIN_NAMESPACE
/*!
 * c++20 类型限定
 */
template <typename T>
concept validtype = std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, double>;

/*!
 * 坐标轴枚举
 */
enum class AxisType
{
	X,
	Y,
	Z
};

/*!
 * 坐标系平面
 */
enum class AxisPlane
{
	XOY,
	YOZ,
	XOZ
};
END_NAMESPACE

#endif