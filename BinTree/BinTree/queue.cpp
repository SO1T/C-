#include "queue.h"
#include <iostream>



queue::queue()
{
}

void queue::push(int key)
{
	length++;
	QUEUE * p = new QUEUE;
	p->key = key;
	p->next = nullptr;

	if (!next)
	{
		next = p;
		next->prev = nullptr;
	}
	else
		while (1)
		{
			if (!next->next)
			{
				next->next = p;
				break;
			}
			QUEUE * temp = next;
			next = next->next;
			next->prev = temp;
		}

	while (1)
	{
		if (!next->prev)
			break;
		next = next->prev;
	}
}


int queue::pop()
{
	int temp = next->key;
	QUEUE *pv = next;

	next = next->next;
	delete pv;
	return temp;
}

int queue::get_len()
{
	return length;
}

void queue::print()
{
	QUEUE * print = next;
	while (print)
	{
		std::cout << print->key << " -> ";
		print = print->next;
	}
	std::cout << std::endl;
}

queue::~queue()
{
}
