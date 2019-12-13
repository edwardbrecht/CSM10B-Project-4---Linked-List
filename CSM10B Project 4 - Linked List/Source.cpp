// Edward Brecht
// 12/12/2019

#include "LinkedList.h"
#include "Point.h"
#include <string>
#include <iostream>

int main()
{
	// test list of type string
	// allocation
	LinkedList<std::string> *stringList = new LinkedList<std::string>;

	// adding to list
	stringList->push_back("Back");
	stringList->push_front("Front");
	stringList->insert("Middle-1", 2);
	stringList->insert("Middle-2", 3);
	stringList->insert("Middle-3", 4);
	
	// get functions
	std::cout << stringList->get_front() << std::endl;
	std::cout << stringList->get_element(2) << std::endl;
	std::cout << stringList->get_back() << std::endl;

	// erase from list
	stringList->erase(3);
	stringList->erase("Middle-1");
	stringList->pop_front();
	stringList->pop_back();

	// deallocation
	delete stringList;

	// test list of type point
	// allocation
	LinkedList<Point> *pointList = new LinkedList<Point>;
	Point *p1 = new Point(1, 1);
	Point *p2 = new Point(1, 2);
	Point *p3 = new Point(1, 3);
	Point *p4 = new Point(1, 4);

	// adding to list
	pointList->push_back(*p4);
	pointList->push_front(*p1);
	pointList->insert(*p2, 2);
	pointList->insert(*p3, 3);

	// get functions
	std::cout << pointList->get_front() << std::endl;
	std::cout << pointList->get_element(2) << std::endl;
	std::cout << pointList->get_back() << std::endl;

	// erase from list
	pointList->erase(*p2);
	pointList->erase(3);
	pointList->pop_front();
	pointList->pop_back();

	// deallocation
	delete pointList;
	delete p1;
	delete p2;
	delete p3;
	delete p4;

	// exit program
	return(EXIT_SUCCESS);
}