/*
https://www.acmicpc.net/problem/1966 프린터 큐 문제 풀이

우선순위 별 큐를 여러개 두어 풀음
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
			// 첫번째보다 우선순위 높은 문서가 있는지 확인
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
				// 뒤로 보내기
				main_q.push(main_q.front());
				main_q.pop();
			}
			else
			{
				// 없으므로 첫번째 인쇄
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