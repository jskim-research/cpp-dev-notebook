#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	// 좀 비효율적인듯 지금
	int N;
	int* A;
	int* answer;
	stack<int> s;

	scanf("%d", &N);

	A = new int[N];
	answer = new int[N];

	for (int i = 0; i < N; i++)
		answer[i] = -1;

	for (int i = 0; i < N; i++)
	{
		int a;

		scanf("%d", &a);
		A[i] = a;

		while (!s.empty())
		{
			if (A[s.top()] < a)
			{
				answer[s.top()] = a;
				s.pop();
			}
			else
			{
				break;
			}
		}

		s.push(i);
	}

	for (int i = 0; i < N - 1; i++)
		printf("%d ", answer[i]);
	printf("%d", answer[N - 1]);

	return 0;
}