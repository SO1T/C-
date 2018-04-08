#pragma once


namespace Program
{
	struct STACK
	{
		int key;
		STACK *next;
	};

	class Stack
	{
	private:
		STACK *next;
	public:
		Stack();
		void Print();
		void Push(int num);
		int Pop();
		Stack operator=(const Stack&);
		~Stack();
	};
}
