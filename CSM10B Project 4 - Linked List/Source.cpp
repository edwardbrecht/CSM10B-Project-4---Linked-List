#include "LinkedList.h"
#include <string>

int main()
{
	LinkedList<std::string> *stringList = new LinkedList<std::string>;
	stringList->push_back("Back");
	stringList->push_front("Front");
	stringList->insert("Middle-1",2);
	stringList->insert("Middle-2",3);
	stringList->erase(2);
	stringList->erase("Back");
	stringList->pop_front();
	system("pause");
}