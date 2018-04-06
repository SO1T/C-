#pragma once


namespace Program
{
	struct student
	{
		char* name;
		int count;
		student * next;
	};
	class list
	{
	private:
		student * next;
	public:
		list();
		void add(char* name, int i);
		~list();
	};
}
