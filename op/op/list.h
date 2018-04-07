#pragma once
#include <string>

namespace Program
{
	struct student
	{
		std::string name;
		double mark;
		student * next;
	};

	class list
	{
	private:
		student * next;
	public:
		list();
		void add(std::string name, double i);
		void print();
		~list();
	};
}
