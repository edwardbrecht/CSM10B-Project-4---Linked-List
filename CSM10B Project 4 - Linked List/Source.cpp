#include "LinkedList.h"
#include <string>

int main()
{
	LinkedList<std::string> *stringList = new LinkedList<std::string>;
	stringList->push_back("Back");
	stringList->push_front("Front");

	system("pause");
}