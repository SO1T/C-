#pragma once

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
		void print_inoder();
		void print(Node *tree);
		~tree();
	};
}
