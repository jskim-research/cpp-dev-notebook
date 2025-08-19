#pragma once
#include <iostream>
#include <math.h>


const double PI = 2.0 * acos(0.0);


class Vector2
{
private:
	double X;
	double Y;

public:
	explicit Vector2(double _X = 0, double _Y = 0) : X(_X), Y(_Y)
	{}

	// 비교 연산
	bool operator == (const Vector2& rhs) const
	{
		return (X == rhs.X && Y == rhs.Y);
	}

	bool operator < (const Vector2& rhs) const
	{
		// 수학적 의미는 없으나 예를 들어 정렬할 때 유용
		return (X != rhs.X)? X < rhs.X : Y < rhs.Y;
	}

	Vector2 operator + (const Vector2& rhs) const
	{
		return Vector2(X + rhs.X, Y + rhs.Y);
	}

	Vector2 operator - (const Vector2& rhs) const
	{
		return Vector2(X - rhs.X, Y - rhs.Y);
	}

	Vector2 operator * (double rhs) const
	{
		return Vector2(X * rhs, Y * rhs);
	}

	// 벡터의 길이 반환
	double Norm() const
	{
		return sqrt(X * X + Y * Y);
	}

	Vector2 Normalize() const
	{
		return Vector2(X / Norm(), Y / Norm());
	}

	// x축 양의 방향으로부터 이 벡터까지의 반시계 반향 각도
	double Polar() const
	{
		// atan2 의 출력은 -pi ~ pi 이므로 0 ~ 2pi 로 다음과 같이 바꿔줌 
		return fmod(atan2(Y, X) + 2 * PI, 2 * PI);
	}

	double Dot(const Vector2& rhs) const
	{
		return X * rhs.X + Y * rhs.Y;
	}

	double Cross(const Vector2& rhs) const
	{
		return X * rhs.Y - Y * rhs.X;
	}

	// 이 벡터를 rhs 에 사영한 결과
	Vector2 Project(const Vector2& rhs) const
	{
		Vector2 r = rhs.Normalize();
		return r * r.Dot(*this);
	}

	double GetX() const
	{
		return X;
	}

	double GetY() const
	{
		return Y;
	}
};