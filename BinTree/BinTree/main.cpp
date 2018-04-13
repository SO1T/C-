#include "tree.h"
#include <iostream>

using namespace std;
using b_tree::tree;

int main()
{
	tree bin_tree;

	bin_tree.add(9);
	bin_tree.add(3);
	//bin_tree.add(4);
	//bin_tree.add(20);
	//bin_tree.add(1);
	//bin_tree.add(15);
	//bin_tree.add(23);
	//bin_tree.add(50);

	bin_tree.print_inoder();
	
	system("pause");
	return 0;
}