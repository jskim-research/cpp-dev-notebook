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

	// �� ����
	bool operator == (const Vector2& rhs) const
	{
		return (X == rhs.X && Y == rhs.Y);
	}

	bool operator < (const Vector2& rhs) const
	{
		// ������ �ǹ̴� ������ ���� ��� ������ �� ����
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

	// ������ ���� ��ȯ
	double Norm() const
	{
		return sqrt(X * X + Y * Y);
	}

	Vector2 Normalize() const
	{
		return Vector2(X / Norm(), Y / Norm());
	}

	// x�� ���� �������κ��� �� ���ͱ����� �ݽð� ���� ����
	double Polar() const
	{
		// atan2 �� ����� -pi ~ pi �̹Ƿ� 0 ~ 2pi �� ������ ���� �ٲ��� 
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

	// �� ���͸� rhs �� �翵�� ���
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