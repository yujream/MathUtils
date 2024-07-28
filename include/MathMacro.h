#ifndef __MATH_MACRO_H__
#define __MATH_MACRO_H__

// dll import export
#ifdef MATH_UTILS_DLL
#define MATH_API __declspec(dllexport)
#else
#define MATH_API __declspec(dllimport)
#endif

// namespace
#define BEGIN_NAMESPACE namespace math \
	{
#define END_NAMESPACE }

#endif