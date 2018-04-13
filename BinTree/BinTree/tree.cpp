#include "tree.h"
#include "queue.h"
#include <iostream>
#include <vector>
#include <iomanip>

queue print_queue;

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
		for (int i(0); i <= height; i++)
			print_row(root, height, i);
	}

	void tree::print_row(Node * tree, int height, int depth)
	{
		get_line(tree, depth);
		std::cout << std::setw((height - depth) * 2);
		bool toggle = true;
		if (print_queue.get_len() > 1)
		{
			for (int i(0); i < print_queue.get_len(); i++)
			{
				if (print_queue.pop() != 1337) //fix it
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
		for (int i(0); i < print_queue.get_len(); i++)
		{
			int key = print_queue.pop();
			if (key != 1337)
				std::cout << key << "   ";
		}
		std::cout << std::endl;
	}

	void tree::get_line(Node * tree, int depth)
	{
		if (depth <= 0 && tree != nullptr)
		{
			print_queue.push(tree->num);
			return;
		}
		if (tree->left != nullptr)
			get_line(tree->left, depth - 1);
		else if (depth - 1 <= 0)
			print_queue.push(1337);
		if (tree->right != nullptr)
			get_line(tree->right, depth - 1);
		else if (depth - 1 <= 0)
			print_queue.push(1337);
	}

	tree::~tree()
	{
	}
}