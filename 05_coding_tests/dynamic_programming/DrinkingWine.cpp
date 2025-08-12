#include <iostream>

using namespace std;

int A[10001];
int memo[10001];

int Solve(int n)
{
	if (n <= 0) return 0;
	if (memo[n] != -1) return memo[n];

	int ret = -1;

	ret = Solve(n - 1);

	ret = max(ret, A[n] + Solve(n - 2));

	ret = max(ret, A[n] + A[n - 1] + Solve(n - 3));

	memo[n] = ret;

	return ret;
}

int main(void)
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < 10001; i++) memo[i] = -1;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &A[i + 1]);
	}

	printf("%d\n", Solve(n));


	return 0;
}