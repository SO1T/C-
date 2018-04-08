#pragma once

namespace Program
{
	struct Node
	{
		int key;
		Node *next;
		Node *prev;
	};

	class list
	{
	private:
		Node * head;
		Node * tail;
	public:
		list();
		void push(int num);
		void print();
		list operator=(const list& l);
		~list();
	};

}