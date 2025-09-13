#include <iostream>
#include <vector>
#include <cmath>
#include "GeometryLibrary.h"
using namespace std;

int main(void)
{
	vector<Vector2> points;
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		double x, y;
		scanf("%lf %lf", &x, &y);
		points.push_back(Vector2(x, y));
	}

	// �ִ밪�� 4e14 �����̹Ƿ� double ��������
	double sum = 0;
	// ���� �ﰢ���� ������ �� �����Ƿ� Shoelace ���� ���
	for (int i = 0; i < N; i++)
	{
		int j = (i + 1) % N;
		sum += points[i].Cross(points[j]);
	}

	double answer = abs(sum) / 2.0;
	printf("%.1f\n", answer);

	return 0;
}