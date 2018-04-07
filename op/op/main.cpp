#include <iostream>
#include <fstream>
#include <string>
#include "list.h"

using namespace std;
using Program::list;

int main()
{
	list student;
	ifstream fin("students.csv");

	
	char buff[50];
	fin.getline(buff, 50);
	int count = stoi(buff);

	string **file = new string*[count];

	for (int i(0); i < count; i++)
	{
		int columns = 1;
		fin.getline(buff, 50);
		for (int k(0); buff[k] != 0; k++)
			if (buff[k] == ',')
				columns++;
		file[i] = new string[columns];
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
			student.add(file[i][0], res);
		}
	}

	student.print();
	
	/*for (int i(0); i < 80; i++)
	{
		for (int j(0); j < 7; j++)
		{
			cout << file[i][j] << " ";
		}
		cout << endl;
	}*/
	
	fin.close();
	
	system("pause");
	return 0;
}