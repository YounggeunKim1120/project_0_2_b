#include <stdio.h>
#include "function.h"

extern float tempVec[10];
extern float tempMat[10][10];

int main(void)
{
	//matrices
	float A[3][3] = {
		{11,5,4},
		{9,7,5},
		{3,15,4}
	};
	float H_tilde[3][3] = {
		{1,4,9},
		{4,4,6},
		{2,8,5}
	};
	float H[3][3] = { 0, };
	float H_transposed[3][3] = { 0, };
	float B[3][3] = { 0, };

	//temporal column vector and matrix
	float tempV[3] = { 0, };
	float tempM[3][3] = { 0, };

	//size of matrices
	int n = 3;

	//index
	int i, j;

	// get H from H_tilde
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			tempV[j] = H_tilde[j][i];
		}
		normalizeVec(tempV, n);
		for (j = 0; j < n; j++)
		{
			H[j][i] = tempVec[j];
		}
	}

	//get H_transposed from H
	transposeMat(H, n, n);
	getTempMat(H_transposed, n, n);

	//get and show B 
	multiplyMat(H_transposed, n, n, A, n, n);
	getTempMat(tempM, n, n);

	multiplyMat(tempM, n, n, H, n, n);
	getTempMat(B, n, n);

	printf("Matrix B)\n");
	printTempMat(n, n);
	
	//show C
	multiplyMat(H, n, n, B, n, n);
	getTempMat(tempM, n, n);
	multiplyMat(tempM, n, n, H_transposed, n, n);

	printf("Matrix C)\n");
	printTempMat(n, n);
}