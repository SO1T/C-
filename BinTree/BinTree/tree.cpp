#include "tree.h"
#include "queue.h"
#include <iostream>

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
				pv = pv->left;
			else
				pv = pv->right;
		}

		if (!root)
			root = temp;
		

		else if (mpv->num > data)
			mpv->left = temp;
		else
			mpv->right = temp;

	}

	void tree::print_inoder()
	{
		print(root);
		print_queue.print();
	}


	void tree::print(Node * tree)
	{
		if (tree)
		{
			if (tree->left)
			{
				print(tree->left);	
			}
			if (tree->right)
			{
				print(tree->right);
			}
			print_queue.push(tree->num);
		}
	}

	tree::~tree()
	{
	}
}