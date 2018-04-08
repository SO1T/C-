#include "list.h"
#include <iostream>

namespace Program
{

	list::list()
	{
	}

	void list::push(int num)
	{
		Node *temp = new Node;
		temp->next = nullptr;
		temp->prev = nullptr;
		temp->key = num;

		if (tail)
		{
			tail->next = temp;
			temp->prev = tail;	
		}
		if (!head)
		{
			head = temp;
		}
		tail = temp;
	}

	void list::print()
	{
		Node *pv = head;
		while (pv)
		{
			std::cout << pv->key << " -> ";
			pv = pv->next;
		}
		std::cout << "NULL" << std::endl;
	}

	list list::operator=(const list& l)
	{
		this->head = new Node;
		this->tail = new Node;
		Node *hmain = l.head;
		Node *tmain = l.tail;
		Node *hcopy = this->head;
		Node *tcopy = this->tail;

		while (hmain)
		{
			hcopy->key = hmain->key;
			hcopy->next = hmain->next;
			tcopy->key = tmain->key;
			tcopy->prev = tmain->prev;
			hcopy = hcopy->next;
			tcopy = tcopy->prev;
			hmain = hmain->next;
			tmain = tmain->prev;
			
		}

		return *this;
	}

	

	list::~list()
	{
	}

}
