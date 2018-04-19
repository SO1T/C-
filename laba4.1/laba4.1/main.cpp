#include "lib.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<string> > grid = create_grid("C:\\Users\\den27\\Desktop\\labirint.txt");
	
	for (int i(0); i < 8; i++)
	{
		for (int j(0); j < 8; j++)
			cout << grid[i][j];
		cout << endl;
	}

	system("pause");
	return 0;
}