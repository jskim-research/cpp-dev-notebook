#include <iostream>
#include <queue>

using namespace std;

struct Command
{
	int T;
	char Dir;

	Command(int _T, char _Dir) : T(_T), Dir(_Dir) {}
};

struct Pos
{
	int x;
	int y;

	Pos(int _x, int _y) : x(_x), y(_y) {}
};

int main(void)
{
	enum {UP=0, RIGHT, DOWN, LEFT};
	enum {EMPTY, APPLE, BODY};
	int N, K, L;
	int T = 0;
	int cx = 0, cy = 0;  // 좌측 위 시작
	int snake_dir = RIGHT; // 오른쪽 바라보면서 시작
	int** Map;
	queue<Command> cq;
	queue<Pos> snake_body;
	snake_body.push(Pos(cx, cy));

	scanf("%d %d", &N, &K);

	Map = new int*[N];
	for (int i = 0; i < N; i++)
	{
		Map[i] = new int[N];
		for (int j = 0; j < N; j++)
			Map[i][j] = EMPTY;
	}

	Map[0][0] = BODY;

	for (int i = 0; i < K; i++)
	{
		int row, col;
		scanf("%d %d", &row, &col);

		// 사과 존재 여부
		Map[row - 1][col - 1] = APPLE;
	}

	scanf("%d", &L);

	for (int i = 0; i < L; i++)
	{
		int t;
		char dir;

		scanf("%d %c", &t, &dir);

		cq.push(Command(t, dir));
	}

	int cur_t = 0;

	while (true)
	{
		cur_t++;

		int nx = cx, ny = cy;

		switch (snake_dir)
		{
		case UP:
			ny -= 1;
			break;
		case RIGHT:
			nx += 1;
			break;
		case DOWN:
			ny += 1;
			break;
		case LEFT:
			nx -= 1;
			break;
		}

		// 벽에 부딪힘
		if (ny < 0 || ny >= N || nx < 0 || nx >= N) break;
		// 자기 몸에 부딪힘
		if (Map[ny][nx] == BODY) break;
		else if (Map[ny][nx] == APPLE)
		{
			// 그 칸으로 몸 확장
			cx = nx;
			cy = ny;
			Map[cy][cx] = BODY;
			snake_body.push(Pos(cx, cy));
		}
		else
		{
			// 꼬리 줄여줘야함
			cx = nx;
			cy = ny;
			Map[cy][cx] = BODY;
			Map[snake_body.front().y][snake_body.front().x] = EMPTY;
			snake_body.pop();
			snake_body.push(Pos(cx, cy));
		}

		if (cur_t == cq.front().T)
		{
			switch (cq.front().Dir)
			{
			case 'D':
				snake_dir = (snake_dir + 1) % 4;
				break;
			case 'L':
				snake_dir -= 1;
				if (snake_dir < 0) snake_dir = LEFT;
				break;
			}

			cq.pop();
		}
	}

	printf("%d\n", cur_t);

	return 0;
}