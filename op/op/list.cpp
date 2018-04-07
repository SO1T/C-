#include "list.h"
#include <string>
#include <iostream>

namespace Program
{

	list::list()
	{
	}

	void list::add(std::string name, double i)
	{
		student *ins = new student;
		ins->mark = i;
		ins->name = name;
		ins->next = nullptr;
		//this->next = new student;
		
		if (!next)
		{
			ins->next = nullptr;
			next = ins;
			return;
		}
		student *temp1 = next;

		if (temp1->mark > ins->mark)
		{
			ins->next = temp1;
			next = ins;
			return;
		}

		student *temp2 = temp1->next;

		while (temp2)
		{
			if (temp1->mark < ins->mark && ins->mark <= temp2->mark)
			{
				temp1->next = ins;
				ins->next = temp2;
				return;
			}
			temp1 = temp2;
			temp2 = temp2->next;

		}
		temp1->next = ins;
		ins->next = nullptr;

	}

	void list::print()
	{
		student * print = next;
		while (print)
		{
			std::cout << print->name << "::" << print->mark << std::endl;
			print = print->next;
		}
	}


	list::~list()
	{
	}
}