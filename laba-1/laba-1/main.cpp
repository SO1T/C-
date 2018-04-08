#include <iostream>
#include "Stack.h"

using Program::Stack;

int main()
{
	Stack st1;
	Stack st2;
	for (int i(0); i < 10; i++)
	{
		st1.Push(i);
	}

	st1.Print();
	st2 = st1;
	st2.Print();


	system("pause");
	return 0;
}