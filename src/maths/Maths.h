#ifndef MATH_H_
#define MATH_H_


#include <cmath>

namespace Maths
{
	static const float PI = 3.1415926535f;
	static const float EPSILON = 0.0001f;

	inline bool FP_EQUAL(float a, float b)
	{
			return (std::abs(a - b) < Maths::EPSILON);
	}
	float GetRandomFloatNonGame();

	inline float ToRadians( float inDegrees )
	{
		return inDegrees * PI / 180.0f;
	}
	
	inline float ToDegrees( float inRadians )
	{
		return inRadians * 180.0f / PI;
	}
}

#endif
