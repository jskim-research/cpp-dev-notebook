/*
https://www.acmicpc.net/problem/1966 ������ ť ���� Ǯ��

���� ���� �켱������ ���� ���θ� �˸� �Ǳ� ������ priority_queue �� ���� 
���� �����ִ� ���� ���� priority �� ����
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
				// ���� ������ �ְ� �켱�����̹Ƿ� �μ�
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
				// �ڷ� ���� �з���
				q.push(q.front());
				q.pop();
			}
		}

	}
	return 0;
}