// Edward Brecht
// 12/12/2019

#include "Point.h"
#include <cmath>


Point::Point() : m_x{ 0 }, m_y{ 0 }
{
}

//Constructor using C++ 
Point::Point(const int x, const int y) : m_x{ x }, m_y{ y }
{
}

//returns Points X value
int Point::getX() const
{
    return m_x;
}

//sets Points X value
void Point::setX(const int x)
{
    m_x = x;
}

//returns Points Y value
int Point::getY() const
{
    return m_y;
}

//sets Points Y value
void Point::setY(const int y)
{
    m_y = y;
}

//returns Points distance from Origin
double Point::distanceFromOrigin() const
{
    return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

bool Point::operator== (const Point &other) const
{
	if (m_x == other.m_x && m_y == other.m_y)
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

std::ostream& operator<< (std::ostream& output, const Point& point)
{
	output << "(" << point.m_x << ", " << point.m_y << ")";
	return output;
}