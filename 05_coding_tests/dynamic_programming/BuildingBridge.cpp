#include <iostream>

using namespace std;

int memo[30][30];

void Init()
{
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			memo[i][j] = -1;
}

int Solve(int n, int m)
{
	if (n == 0) return 1;  // 모든 다리 놓은 상태
	if (memo[n][m] != -1) return memo[n][m];

	int ret = 0;

	for (int i = n - 1; i <= m - 1; i++)
	{
		ret += Solve(n - 1, i);
	}

	memo[n][m] = ret;

	return ret;
}

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		Init();
		int answer = Solve(n, m);

		printf("%d\n", answer);
	}

	return 0;
}