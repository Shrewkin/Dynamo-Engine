#pragma once

#include "global_header.h"

DE_Matrix DE_Matrix_Set(float f00, float f01, float f02,
					    float f10, float f11, float f12,
						float f20, float f21, float f22);

DE_Matrix DE_Matrix_Identity(void);

DE_Matrix DE_Matrix_From_Vector(DE_Vector2 col1, DE_Vector2 col2, DE_Vector2 col3);

DE_Matrix DE_Matrix_Scale(DE_Vector2 scale);

DE_Matrix DE_Matrix_Translate(DE_Vector2 offset);

DE_Matrix DE_Matrix_Rotate(float deg);
DE_Matrix DE_Matrix_Rotate_Rads(float rad);

DE_Matrix DE_Matrix_Transpose(DE_Matrix original);

DE_Matrix DE_Matrix_Inverse(DE_Matrix original);

DE_Matrix DE_Matrix_Multiply(DE_Matrix a, DE_Matrix b);