#pragma once

#include "global_header.h"

DE_Vector2 DE_Vector_Set(float x, float y);

DE_Vector2 DE_Vector_Zero(void);

DE_Vector2 DE_Vector_Negate(DE_Vector2 vec);

DE_Vector2 DE_Vector_Add(DE_Vector2 a, DE_Vector2 b);

DE_Vector2 DE_Vector_Subtract(DE_Vector2 a, DE_Vector2 b);

DE_Vector2 DE_Vector_Normalize(DE_Vector2 vec);

DE_Vector2 DE_Vector_Scale(DE_Vector2 vec, float scale);

DE_Vector2 DE_Vector_MatrixMultiply(DE_Matrix mat, DE_Vector2 vec);

float DE_Vector_Length(DE_Vector2 vec);

float DE_Vector_Distance(DE_Vector2 a, DE_Vector2 b);

float DE_Vector_DotProduct(DE_Vector2 a, DE_Vector2 b);

float DE_Vector_CrossProduct(DE_Vector2 a, DE_Vector2 b);

float DE_Vector_Angle(DE_Vector2 a, DE_Vector2 b);