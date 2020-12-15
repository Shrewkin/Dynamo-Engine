#pragma once

// Clamp function for float
float DE_Math_Clamp_Float(float value, float min, float max);
// Clamp function for int
int DE_Math_Clamp_Int(int value, int min, int max);
// Lerp function for int
int DE_Math_Lerp_Int(int a, int b, float lerpFactor);
// Lerp function for float
float DE_Math_Lerp_Float(float a, float b, float lerpFactor);
// Square value given
float DE_Math_Square_Value(float value);
// Calculate distance from two points
float DE_Math_Distance(float x1, float y1, float x2, float y2);
// Convert radians to degrees
float DE_Math_Degree(float rad);
// Convert degrees to radians
float DE_Math_Radian(float deg);