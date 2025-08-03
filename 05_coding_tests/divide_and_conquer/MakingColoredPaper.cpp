#include <iostream>

using namespace std;

int map[128][128];

void Solve(int N, int x, int y, int& white, int& blue)
{
	bool AllSame = true;
	for (int i=y; i<y + N; i++)
		for (int j=x; j<x + N; j++)
			if (map[i][j] != map[y][x])
			{
				AllSame = false;
				break;
			}

	if (AllSame)
	{
		if (map[y][x] == 0) white += 1;
		else blue += 1;
	}
	else
	{
		Solve(N / 2, x, y, white, blue);
		Solve(N / 2, x + N/2, y, white, blue);
		Solve(N / 2, x, y + N/2, white, blue);
		Solve(N / 2, x + N/2, y + N/2, white, blue);
	}
}

int main(void)
{
	int N;
	int white = 0, blue = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	Solve(N, 0, 0, white, blue);

	printf("%d\n", white);
	printf("%d\n", blue);

	return 0;
}