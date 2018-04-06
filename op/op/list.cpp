#include "list.h"

namespace Program
{

	list::list()
	{
	}

	void list::add(char * name, int i)
	{
		student *p = new student;
		p->count = i;
		p->name = name;
		p->next = next;
		next = p;
	}


	list::~list()
	{
	}
}