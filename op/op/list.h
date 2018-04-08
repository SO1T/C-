#pragma once
#include <string>
#include <fstream>

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
		int length;
	public:
		list();
		void add(std::string name, double i);
		void create_list(std::ifstream& fin);
		void fill(std::ofstream& fout);
		void print();
		~list();
	};
}
