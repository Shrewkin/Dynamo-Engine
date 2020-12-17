#pragma once

#include "DE_engine_matrix.h"

DE_Matrix DE_Matrix_Set(float f00, float f01, float f02,
					 	float f10, float f11, float f12,
						float f20, float f21, float f22)
{
	DE_Matrix newMat;
	newMat.f00 = f00;
	newMat.f01 = f01;
	newMat.f02 = f02;
	newMat.f10 = f10;
	newMat.f11 = f11;
	newMat.f12 = f12;
	newMat.f20 = f20;
	newMat.f21 = f21;
	newMat.f22 = f22;

	return newMat;
}

DE_Matrix DE_Matrix_Identity(void)
{
	DE_Matrix newMat;
	newMat.f00 = 1;
	newMat.f01 = 0;
	newMat.f02 = 0;
	newMat.f10 = 0;
	newMat.f11 = 1;
	newMat.f12 = 0;
	newMat.f20 = 0;
	newMat.f21 = 0;
	newMat.f22 = 1;

	return newMat;
}

DE_Matrix DE_Matrix_From_Vector(DE_Vector2 col1, DE_Vector2 col2, DE_Vector2 col3)
{
	DE_Matrix newMat;
	newMat.f00 = col1.x; newMat.f01 = col2.x; newMat.f02 = col3.x;
	newMat.f10 = col1.y; newMat.f11 = col2.y; newMat.f12 = col3.y;
	newMat.f20 = 0.0f;	 newMat.f21 = 0.0f;	  newMat.f22 = 0.0f;

	return newMat;
}

DE_Matrix DE_Matrix_Scale(DE_Vector2 scale)
{
	DE_Matrix scaleMat;
	// 
	// k 0
	// 0 k
	// 
	scaleMat.f00 = scale.x; scaleMat.f01 = 0.0f;	scaleMat.f02 = 0.0f;
	scaleMat.f10 = 0.0f;	scaleMat.f11 = scale.y; scaleMat.f12 = 0.0f;
	scaleMat.f20 = 0.0f;	scaleMat.f21 = 0.0f;	scaleMat.f22 = 0.0f;
	return scaleMat;
}

DE_Matrix DE_Matrix_Translate(DE_Vector2 offset)
{
	DE_Matrix transMat;

	transMat.f00 = offset.x; transMat.f01 = offset.x; transMat.f02 = offset.x;
	transMat.f10 = offset.y; transMat.f11 = offset.y; transMat.f12 = offset.y;
	transMat.f20 = 0.0f;	 transMat.f21 = 0.0f;	  transMat.f22 = 0.0f;

	return transMat;
}

DE_Matrix DE_Matrix_Rotate(float deg)
{
	DE_Matrix rotMat;
	if (deg < 0.0f)
	{
		rotMat.f00 =  cosf(deg); rotMat.f01 = sinf(deg); rotMat.f02 = 0.0f;
		rotMat.f10 = -sinf(deg); rotMat.f11 = cosf(deg); rotMat.f12 = 0.0f;
		rotMat.f20 = 0.0f;		 rotMat.f21 = 0.0f;		 rotMat.f22 = 0.0f;
	}
	else
	{
		rotMat.f00 = cosf(deg); rotMat.f01 = -sinf(deg); rotMat.f02 = 0.0f;
		rotMat.f10 = sinf(deg); rotMat.f11 =  cosf(deg); rotMat.f12 = 0.0f;
		rotMat.f20 = 0.0f;		rotMat.f21 = 0.0f;		 rotMat.f22 = 0.0f;
	}

	return rotMat;
}
DE_Matrix DE_Matrix_Rotate_Rads(float rad)
{
	float deg = rad * 180.0f / (float)PI;

	return DE_Matrix_Rotate(deg);
}

DE_Matrix DE_Matrix_Transpose(DE_Matrix original)
{
	//1 2 3
	//4 5 6
	//7 8 9
	//
	//1 4 7
	//2 5 8
	//3 6 9

	DE_Matrix newMat;

	newMat.f00 = original.f00; newMat.f01 = original.f10; newMat.f02 = original.f20;
	newMat.f10 = original.f01; newMat.f11 = original.f11; newMat.f12 = original.f21;
	newMat.f20 = original.f02; newMat.f21 = original.f12; newMat.f22 = original.f22;

	return newMat;
}

DE_Matrix DE_Matrix_Multiply(DE_Matrix a, DE_Matrix b)
{
	DE_Matrix newMat;

	newMat.f00 = a.f00 * b.f00 + a.f01 * b.f10 + a.f02 * b.f20;
	newMat.f01 = a.f00 * b.f01 + a.f01 * b.f11 + a.f02 * b.f21;
	newMat.f02 = a.f00 * b.f02 + a.f01 * b.f12 + a.f02 * b.f22;

	newMat.f10 = a.f10 * b.f00 + a.f11 * b.f10 + a.f12 * b.f20;
	newMat.f11 = a.f10 * b.f01 + a.f11 * b.f11 + a.f12 * b.f21;
	newMat.f12 = a.f10 * b.f02 + a.f11 * b.f12 + a.f12 * b.f22;

	newMat.f20 = a.f20 * b.f00 + a.f21 * b.f10 + a.f22 * b.f20;
	newMat.f21 = a.f20 * b.f01 + a.f21 * b.f11 + a.f22 * b.f21;
	newMat.f22 = a.f20 * b.f02 + a.f21 * b.f12 + a.f22 * b.f22;

	return newMat;
}

DE_Matrix DE_Matrix_Inverse(DE_Matrix original)
{
	DE_Matrix newMat;

	newMat.f00 =   original.f11 * original.f22 - original.f12 * original.f21 ;
	newMat.f01 = -(original.f01 * original.f22 - original.f02 * original.f21);
	newMat.f02 =   original.f01 * original.f12 - original.f02 * original.f11 ;

	newMat.f10 = -(original.f10 * original.f22 - original.f12 * original.f20);
	newMat.f11 =   original.f00 * original.f22 - original.f02 * original.f20 ;
	newMat.f12 = -(original.f01 * original.f12 - original.f02 * original.f10);

	newMat.f20 =   original.f10 * original.f21 - original.f11 * original.f20 ;
	newMat.f21 = -(original.f00 * original.f21 - original.f01 * original.f20);
	newMat.f22 =   original.f00 * original.f11 - original.f01 * original.f10 ;

	return newMat;
}