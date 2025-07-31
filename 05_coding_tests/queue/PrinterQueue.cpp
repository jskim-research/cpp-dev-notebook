/*
https://www.acmicpc.net/problem/1966 ������ ť ���� Ǯ��

�켱���� �� ť�� ������ �ξ� Ǯ��
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
		int cnt = 0;
		bool found = false;
		vector<queue<int>> vq;
		queue<Document> main_q;
		scanf("%d %d", &N, &M);

		for (int j = 0; j < 9; j++)
			vq.push_back(queue<int>());

		for (int j = 0; j < N; j++)
		{
			int priority;

			scanf("%d", &priority);

			vq[priority - 1].push(j);
			main_q.push(Document(j, priority));
		}

		while (!main_q.empty())
		{
			// ù��°���� �켱���� ���� ������ �ִ��� Ȯ��
			bool higher_priority_exist = false;
			for (int j = main_q.front().priority; j < 9; j++)
			{
				if (!vq[j].empty())
				{
					higher_priority_exist = true;
					break;
				}
			}

			if (higher_priority_exist)
			{
				// �ڷ� ������
				main_q.push(main_q.front());
				main_q.pop();
			}
			else
			{
				// �����Ƿ� ù��° �μ�
				cnt++;
				if (main_q.front().order == M)
				{
					printf("%d\n", cnt);
					break;
				}
				else
				{
					vq[main_q.front().priority - 1].pop();
					main_q.pop();
				}

		
			}
		}
	}
	return 0;
}