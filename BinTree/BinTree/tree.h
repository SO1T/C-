#pragma once
#include <vector>

namespace b_tree
{
	struct Node
	{
		int num;
		Node *left;
		Node *right;
	};

	class tree
	{
	private:
		Node * root;
	public:
		tree();
		void add(int num);
		int getHeight();
		int height(Node *root);
		void print_inoder();
		void print(Node *tree);
		void print_row(const Node *tree, const int height, int depth);
		void get_line(const Node *tree, int depth, std::vector<int>& val);
		~tree();
	};
}
