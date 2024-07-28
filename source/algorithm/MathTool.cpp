#include "algorithm/MathTool.h"
#include <numbers>

double math::MathTool::degreeToRadian(const double degree)
{
	return degree * std::numbers::pi / 180;
}

double math::MathTool::radianToDegree(const double radian)
{
	return radian * 180 / std::numbers::pi;
}

float math::MathTool::fraction(float v)
{
	return v - static_cast<int>(v);
}
