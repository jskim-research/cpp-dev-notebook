#include <iostream>

using namespace std;

int A[1001];
int memo[1001];

int Solve(int n)
{
	if (n <= 0) return 0;	
	if (memo[n] != -1) return memo[n];

	int ret = 1;

	// A[n] 을 선택하고 그것보다 작은 값들만 고려하는 경우
	// f(n) = max({f(k) + 1 | a(k) < a(n) and k < n})
	for (int k = 1; k < n; k++)
	{
		if (A[k] < A[n]) ret = max(ret, Solve(k) + 1);
	}

	memo[n] = ret;

	return ret;
}

int main(void)
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < 1001; i++) memo[i] = -1;

	for (int i = 0; i < n; i++)
		scanf("%d", &A[i + 1]);

	int answer = 0;

	for (int i = 1; i <= n; i++)
		answer = max(answer, Solve(i));

	printf("%d\n", answer);

	return 0;
}