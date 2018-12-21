#pragma once

class Point
{
public:
	Point();
	Point(const int x, const int y);
	Point(const Point& other);
	void SetX(const int x);
    void SetY(const int y);
	int Get_X();
	int Get_Y();
	void Show();
private:
	int m_x;
	int m_y;
};

Point::Point()
{
}

Point::Point(const int x, const int y) :
	m_x(x),
	m_y(y)
{
}

Point::Point(const Point& other) :
	m_x(other.m_x),
	m_y(other.m_y)
{
}


void Point::Show()
{
	std::cout << "Coordinate point X:" << m_x << ";Y:" << m_y;
}

void Point::SetX(const int x)
{
	m_x = x;
}

void Point::SetY(const int y)
{
	m_y = y;
}

int Point::Get_X()
{
	return m_x;
}

int Point::Get_Y()
{
	return m_y;
}
