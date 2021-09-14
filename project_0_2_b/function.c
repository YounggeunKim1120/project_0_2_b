//function file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float tempMat[10][10] = { 0, };
float tempVec[10] = { 0, };

void printTempMat(int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%0.1f ", tempMat[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void printTempVec(int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%1f ", tempVec[i]);
	}
	printf("\n\n");
}

void transposeMat(float* A, int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			tempMat[j][i] = *(A + i * n + j);
		}
	}
}

void normalizeVec(float* v, int n)
{
	float c;
	float squared_c = 0;
	int i;

	for (i = 0; i < n; i++)
	{
		squared_c += v[i] * v[i];
	}

	c = sqrt(squared_c);

	for (i = 0; i < n; i++)
	{
		tempVec[i] = v[i] / c;
	}
}

float calculateLen(float* v, int n)
{
	float c;
	float squared_c = 0;
	int i;

	for (i = 0; i < n; i++)
	{
		squared_c += v[i] * v[i];
	}

	c = sqrt(squared_c);

	return c;
}

void scaleMat(float* A, int m, int n, float c)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			tempMat[i][j] = c * *(A + i * n + j);
		}
	}
}

int multiplyMat(float* A, int m, int n, float* B, int l, int k)
{
	int i, j, h;

	float tempEnt;

	if (n == l)
	{
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < k; j++)
			{
				tempMat[i][j] = 0;
				for (h = 0; h < n; h++)
				{
					tempMat[i][j] += (*(A + i * n + h)) * (*(B + h * k + j));
				}
			}
		}
		return 1;
	}
	else
		return 0;
}

int addMat(float* A, int m, int n, float* B, int l, int k)
{
	int i, j;

	float tempEnt;

	if (m == l || n == k)
	{
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < k; j++)
			{
				tempMat[i][j] = (*(A + i * n + j)) + (*(B + i * n + j));
			}
		}
		return 1;
	}
	else
		return 0;
}

void getTempMat(float* A, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			*(A + i * n + j) = tempMat[i][j];
		}
	}
}
