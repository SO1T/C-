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
	student.create_list(fin);
	fin.close();
	ofstream fout("fstudents.csv");
	student.fill(fout);
	fout.close();
	
	return 0;
}