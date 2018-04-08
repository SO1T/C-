#include "list.h"
#include <string>
#include <iostream>

namespace Program
{

	list::list()
	{
		this->length = 0;
	}

	void list::add(std::string name, double i)
	{
		this->length++;
		student *ins = new student;
		ins->mark = i;
		ins->name = name;
		ins->next = nullptr;
		
		if (!next)
		{
			ins->next = nullptr;
			next = ins;
			return;
		}
		student *temp1 = next;

		if (temp1->mark < ins->mark)
		{
			ins->next = temp1;
			next = ins;
			return;
		}

		student *temp2 = temp1->next;

		while (temp2)
		{
			if (temp1->mark > ins->mark && ins->mark >= temp2->mark)
			{
				temp1->next = ins;
				ins->next = temp2;
				return;
			}
			temp1 = temp2;
			temp2 = temp2->next;
		}
		temp1->next = ins;
		ins->next = nullptr;

	}

	void list::create_list(std::ifstream& fin)
	{	
		char buff[50];
		fin.getline(buff, 50);
		int count = std::stoi(buff);

		std::string **file = new std::string*[count];

		for (int i(0); i < count; i++)
		{
			int columns = 1;
			fin.getline(buff, 50);
			for (int k(0); buff[k] != 0; k++)
				if (buff[k] == ',')
					columns++;
			file[i] = new std::string[columns];
			int in = 0;
			for (int j(0); j < columns; j++)
			{
				while (buff[in] != ',' && buff[in] != 0)
				{
					file[i][j] += buff[in];
					in++;
				}
				in++;
			}
			if (file[i][columns - 1] == "TRUE")
			{
				double mark = 0;
				int counter = columns - 2;
				while (counter > 0)
				{
					mark += stoi(file[i][counter]);
					counter--;
				}
				double res = mark / (columns - 2);
				this->add(file[i][0], res);
			}
		}

		for (int i(0); i < count; i++)
			delete[] file[i];
		delete[] file;
	}

	void list::fill(std::ofstream & fout)
	{
		int num = this->length;
		int st = num / 100.0 * 40;
		student *print = next;
		while (st != 0)
		{
			fout << print->name << ",";
			fout << std::fixed;
			fout.precision(2);
			fout << print->mark << std::endl;
			print = print->next;
			st--;
		}

	}

	list::~list()
	{
		if (!next) return;
		student *dl = next;
		student *pv;
		while (dl)
		{
			pv = dl;
			dl = dl->next;
			delete pv;
		}
		next = nullptr;
	}
}