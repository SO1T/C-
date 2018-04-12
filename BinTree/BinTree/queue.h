#pragma once

struct QUEUE
{
	int key;
	int level;
	QUEUE *next;
	QUEUE *prev;
};

class queue
{
private:
	QUEUE * next;
public:
	queue();
	void push(int key);
	int pop();
	void print();
	~queue();
};

