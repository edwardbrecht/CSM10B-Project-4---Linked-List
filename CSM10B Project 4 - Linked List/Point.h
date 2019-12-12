// Edward Brecht
// 12/10/2019

#pragma once
#include <iostream>

class Point
{
public:
    //Function Prototypes for public member functions
    Point(const int x, const int y);

    int getX() const;
    void setX(const int x);

    int getY() const;
    void setY(const int y);

    double distanceFromOrigin() const;

	friend std::ostream& operator<< (std::ostream& output, const Point& point);

private:

    int m_x = 0;
    int m_y = 0;


};

