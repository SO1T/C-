#include "lib.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>


using namespace std;

vector<vector<string> > create_grid(string str)
{
	ifstream fin(str);
	char buff[50];
	
	int i = 0;
	int j = 0;

	while (!fin.eof())
	{
		fin.getline(buff, 50);
		while (buff[j] != '\0')
			j++;
		i++;
	}
	
	vector<vector<string> > grid;
	grid.resize(i);

	for (int k(0); k < grid.size(); k++)
		grid[k].resize(j);

	fin.clear();
	fin.seekg(0, ios::beg);

	for (int k(0); k < grid.size(); k++)
	{
		fin.getline(buff, 50);
		for (int x(0); x < grid[k].size(); x++)
		{
			grid[k][x] = buff[x];
		}
	}

	return grid;
}