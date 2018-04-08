#include "Stack.h"
#include <iostream>

 

namespace Program
{

	Stack::Stack()
	{
	}

	void Stack::Print()
	{
		STACK *print = next;

		while (print)
		{
			std::cout << print->key << " - > ";
			print = print->next;
		}
		std::cout << "NULL" << std::endl;
	}

	void Stack::Push(int num)
	{
		STACK *pv = new STACK;
		pv->key = num;
		pv->next = next;
		next = pv;
	}

	int Stack::Pop()
	{
		int pop = next->key;
		STACK *pv = next;

		next = next->next;
		delete pv;
		return pop;
	}

	Stack Stack::operator=(const Stack& stack) 
	{
		this->next = new STACK;
		STACK *copy = stack.next;
		STACK *end = this->next;
		while (copy)
		{
			end->key = copy->key;
			end->next = copy->next;
			end = end->next;
			copy = copy->next;
		}
		return *this;
	}

	Stack::~Stack()
	{
	}
}