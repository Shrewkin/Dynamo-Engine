#include "global_header.h"
#include "DE_engine_math.h"


// Math functions
// clamps for int and float
float DE_Math_Clamp_Float(float value, float min, float max)
{
	if (value > min && value < max)
		return value;
	if (value < min)
		return min;
	if (value > max)
		return max;
	return 0.0f;
}

int DE_Math_Clamp_Int(int value, int min, int max)
{
	return (int)DE_Math_Clamp_Float((float)value, (float)min, (float)max);
}

// Lerp for int and float
int DE_Math_Lerp_Int(int a, int b, float lerpFactor)
{
	return a + (int)lerpFactor * (b - a);
}

float DE_Math_Lerp_Float(float a, float b, float lerpFactor)
{
	return a + lerpFactor * (b - a);
}

// Square functions
float DE_Math_Square_Value(float value)
{
	return value * value;
}

// distance calculations
float DE_Math_Distance(float x1, float y1, float x2, float y2)
{
	DE_Vector2 distance;
	distance.x = x2 - x1;
	distance.y = y2 - y1;

	return sqrtf(DE_Math_Square_Value(distance.x) + DE_Math_Square_Value(distance.y));
}

// degree to radians and vice versa
float DE_Math_Degree(float rad)
{
	return rad * 180.0f / (float)PI;
}

float DE_Math_Radian(float deg)
{
	return deg * (float)PI / 180.0f;
}