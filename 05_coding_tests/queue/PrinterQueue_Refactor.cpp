/*
https://www.acmicpc.net/problem/1966 프린터 큐 문제 풀이

가장 높은 우선순위의 존재 여부만 알면 되기 때문에 priority_queue 를 통해 
현재 남아있는 가장 높은 priority 값 추적
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Document
{
	int order;
	int priority;
	Document(int _order, int _priority) : order(_order), priority(_priority) {}
};

int main(void)
{
	int T, N, M;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		queue<Document> q;
		priority_queue<int> pq;
		scanf("%d %d", &N, &M);

		for (int j = 0; j < N; j++)
		{
			int priority;

			scanf("%d", &priority);

			q.push(Document(j, priority));
			pq.push(priority);
		}

		while (!q.empty())
		{
			if (pq.top() == q.front().priority)
			{
				// 현재 문서가 최고 우선순위이므로 인쇄
				if (q.front().order == M)
				{
					printf("%d\n", N - q.size() + 1);
					break;
				}
				else
				{
					pq.pop();
					q.pop();
				}
			}
			else
			{
				// 뒤로 순서 밀려남
				q.push(q.front());
				q.pop();
			}
		}

	}
	return 0;
}