// Edward Brecht
// 12/10/2019

#include "LinkedList.h"
#include <string>
#include <iostream>

int main()
{
	LinkedList<std::string> *stringList = new LinkedList<std::string>;
	stringList->push_back("Back");
	stringList->push_front("Front");
	stringList->insert("Middle-1", 2);
	stringList->insert("Middle-2", 3);
	
	std::cout << stringList->get_front() << std::endl;
	std::cout << stringList->get_element(2) << std::endl;
	std::cout << stringList->get_back() << std::endl;

	stringList->erase(3);
	stringList->pop_front();
	stringList->pop_back();

	delete stringList;

	system("pause");
}