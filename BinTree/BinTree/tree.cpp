#include "tree.h"
#include <iostream>
#include <vector>
#include <iomanip>



namespace b_tree
{

	tree::tree()
	{
	}

	void tree::add(int data)
	{
		Node *temp = new Node;
		temp->num = data;
		temp->left = nullptr;
		temp->right = nullptr;
		
		Node *pv = root;
		Node *mpv = nullptr;

		while (pv)
		{
			mpv = pv;
			if (pv->num > data)
			{
				pv = pv->left;
			}
			else
			{
				pv = pv->right;
			}
		}

		if (!root)
			root = temp;
		

		else if (mpv->num > data)
		{
			mpv->left = temp;
		}
		else
		{
			mpv->right = temp;
		}
	}

	int tree::getHeight()
	{
		return height(root);
	}

	int tree::height(Node * root)
	{
		int r = 0;
		int l = 0;
		if (root)
		{
			if (root->left)
			{
				l = height(root->left) + 1;
			}
			if (root->right)
			{
				r = height(root->right) + 1;
			}
		}
		return r >= l ? r : l;
	}

	void tree::print_inoder()
	{
		print(root);
	}


	void tree::print(Node * tree)
	{
		int height = getHeight() * 2;
		if (height == 0)
			std::cout << tree->num << std::endl;
		else
			for (int i(0); i < height; i++)
				print_row(root, height, i);
	}

	void tree::print_row(const Node * tree, const int height, int depth)
	{
		std::vector<int> print_vector;
		get_line(tree, depth, print_vector);
		std::cout << std::setw((height - depth) * 2);
		bool toggle = true;
		if (print_vector.size() > 1)
		{
			for (int key : print_vector)
			{
				if (key != 1337)
				{
					if (toggle)
						std::cout << "/" << "   ";
					else
						std::cout << "\\" << "   ";
				}
				toggle = !toggle;
			}
			std::cout << std::endl;
			std::cout << std::setw((height - depth) * 2);
		}
		for (int key : print_vector)
		{
			if (key != 1337)
			std::cout << key << "   ";
		}
		std::cout << std::endl;
	}

	void tree::get_line(const Node * tree, int depth, std::vector<int>& val)
	{
		if (depth <= 0 && tree != nullptr)
		{
			val.push_back(tree->num);
			return;
		}
		if (tree->left != nullptr)
			get_line(tree->left, depth - 1, val);
		else if (depth - 1 <= 0)
			val.push_back(1337);
		if (tree->right != nullptr)
			get_line(tree->right, depth - 1, val);
		else if (depth - 1 <= 0)
			val.push_back(1337);
	}

	tree::~tree()
	{
	}
}