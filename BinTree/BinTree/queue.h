#pragma once

struct QUEUE
{
	int key;
	QUEUE *next;
	QUEUE *prev;
};

class queue
{
private:
	QUEUE * next;
	int length;
public:
	queue();
	void push(int key);
	int pop();
	int get_len();
	void print();
	~queue();
};

