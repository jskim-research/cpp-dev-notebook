#include <iostream>

using namespace std;

int** A;
int N;  // 행렬 크기

void MatrixMultiplication(int** mat1, int** mat2, int*** result)
{
	int** tmp = new int* [N];
	for (int i = 0; i < N; i++) tmp[i] = new int[N];

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			tmp[i][k] = 0;
			for (int j = 0; j < N; j++)
			{
				tmp[i][k] = (tmp[i][k] + mat1[i][j] * mat2[j][k]) % 1000;
			}
		}
	}

	*result = tmp;
}

void Solve(int*** matrix, long long B)
{
	if (B == 1)
	{
		*matrix = A;
		return;
	}

	int** result;

	Solve(matrix, B / 2);  // half square matrix
	MatrixMultiplication(*matrix, *matrix, &result);  // full square matrix

	if (B % 2 != 0) MatrixMultiplication(result, A, &result);

	*matrix = result;
}

int main(void)
{
	long long B;
	int** answer;
	scanf("%d %lld", &N, &B);

	answer = new int*[N];
	for (int i = 0; i < N; i++) answer[i] = new int[N];

	A = new int* [N];
	for (int i = 0; i < N; i++) A[i] = new int[N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &A[j][i]);
			A[j][i] %= 1000;
		}
	}

	Solve(&answer, B);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", answer[j][i]);
		}
		printf("\n");
	}

	return 0;
}