#ifndef __MATH_TOOL_H__
#define __MATH_TOOL_H__

#include "MathMacro.h"

BEGIN_NAMESPACE

class MATH_API MathTool
{
public:
	/**
	 * @brief 角度转弧度
	 * @param degree 角度
	 * @return
	 */
	static double degreeToRadian(const double degree);

	/**
	 * @brief 弧度转角度
	 * @param radian 弧度
	 * @return 角度
	 */
	static double radianToDegree(const double radian);

	/**
	 * @brief 取小数部分
	 * @param v 浮点数
	 * @return 小数部分
	 */
	static float fraction(float v);
};

END_NAMESPACE

#endif