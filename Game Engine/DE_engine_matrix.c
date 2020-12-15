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

//DE_Matrix DE_matrix_from_vector(DE_Vector2 col1, DE_Vector2 col2, DE_Vector2 col3)
//{
//	reutrn NULL;
//}
//
//DE_Matrix DE_matrix_scale(DE_Vector2 scale)
//{
//	reutrn NULL;
//}
//
//DE_Matrix DE_matrix_translate(DE_Vector2 offset)
//{
//	reutrn NULL;
//}
//
//DE_Matrix DE_matrix_rotate(float deg);
//{
//
//	reutrn NULL;
//}
//DE_Matrix DE_matrix_rotate_rads(float rad)
//{
//
//	reutrn NULL;
//}

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

}

DE_Matrix DE_Matrix_Inverse(DE_Matrix original)
{
	DE_Matrix newMat;
}
