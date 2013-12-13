#include"Dictionary.h"
#include <iostream>
#include<string>
//Komment ot Maksimki
using namespace std;

BinaryTree::BinaryTree()
{ 
	cout << "Consrtuctor" << endl;
	size = 0;
	count1 = 1;
	root = 0;
}

BinaryTree::~BinaryTree()
{
	if (root)
	{
		if (root->right)
			delTree(root->left);
		if (root->left)
			delTree(root->right);
		delete root;
	}
}

void BinaryTree::copy(Node *x, Node *xnew)
{
	if (x->right)
	{
		Node *curr = new Node;
		curr->key = x->right->key;
		curr->value = x->right->value;
		curr->parent = xnew;
		xnew->right=curr;
		copy(x->right, curr);
	}
	if (x->left)
	{
		Node *curr = new Node;
		curr->key = x->left->key;
		curr->value = x->left->value;
		curr->parent = xnew;
		xnew->left=curr;
		copy(x->left, curr);
	}
}


BinaryTree :: BinaryTree(const BinaryTree& temp) 
{
	root = temp.root;
	copy(root, temp.root); 
}

int BinaryTree::getsize()
{
	return size;
}



void BinaryTree::add(int key, string value)
{
	Node *cur = root;
	if(!root)
	{
		root = new Node;
		root->key = key;
		root->value = value;
		root->left = root->right = 0;
	}

	else 
	{
		while((cur->right != 0 && cur->left != 0) || cur->key != key)
		{
			if(key > cur->key)
			{
				if(cur->right == 0)
				{
					Node *temp = cur;
					cur->right = new Node;
					cur = cur->right;
					cur->parent = temp;
					cur->key = key;
					cur->value = value;
					cur->right = cur->left = 0;
				}
				else cur = cur->right;
			}
			if(key < cur->key)
			{
				if(cur->left == 0)
				{
					Node *temp = cur;
					cur->left = new Node;
					cur = cur->left;
					cur->parent = temp;
					cur->key = key;
					cur->value = value;
					cur->left = cur->right = 0;
				}
				else cur = cur->left;
			}
		}
	}
}

void BinaryTree::search(int key)
{
	int flag = 0;
	Node *cur = root;
	while(cur)
	{
		if(key > cur->key)
		{
			cur = cur->right;
		}
		else if(key < cur->key)
		{
			cur = cur->left;
		}
		else if(cur->key == key)
		{
			cout << cur->value << endl;
			flag = 1;
			break;
		}
	}
	if(flag == 0) cout << "no element" << endl;
}

void BinaryTree::show(Node *root, int level)
{
	
	Node *cur = root;
	if(root)
	{
		show(root->right, level + 1);
		for(int i = 0; i < level; i++)
			cout << "  ";
		cout << root->key <<" "<< root->value << endl;
		show(root->left, level + 1);
	}
}

void BinaryTree::print()
{
	this->show(this->getRoot(), 0);
}

void BinaryTree::del(int key)
{
	Node *cur = root;

	while (cur)
	{
		if(key > cur->key)
		{
			cur = cur->right;
		}
		else if(key < cur->key)
		{
			cur = cur->left;
		}
		else if(cur->key == key) break;
	}

	if(cur->left == 0 && cur->right == 0)
	{
		Node *temp = cur->parent;
		if(temp->left == cur)
		{
			delete cur;
			temp->left = 0;
		}
		if(temp->right == cur)
		{
			delete cur;
			temp->right = 0;
		}
	}

	else
	{
		Node *temp = cur;
		if(cur->right == 0)
		{
			cur = cur->left;
			while(cur->right != 0)
			{
				cur = cur->right;
			}
			temp->key = cur->key;
			temp->value = cur->value;
		}

		if(cur->left == 0)
		{
			cur = cur->right;
			while(cur->left != 0)
			{
				cur = cur->left;
			}
			temp->key = cur->key;
			temp->value = cur->value;
		}

		if(cur->right == 0 && cur->left == 0)
		{
			Node *temp = cur->parent;
			if(temp->left == cur)
			{
				delete cur;
				temp->left = 0;
			}
			if(temp->right == cur)
			{
				delete cur;
				temp->right = 0;
			}
		}

		else
		{
			if(cur->right != 0 && cur->left != 0)
			{
				Node *temp = cur;
				Node *cur1 = cur->parent;
				if(temp->right != 0)
				{
					temp = temp->right;
					if(temp->left != 0)
					{
						while(temp->left != 0)
						{
							temp = temp->left;
						}
						cur->key = temp->key;
						cur->value = temp->value;
						temp->parent->left = 0;
						delete temp;
					}
					else 
					{
						cur->key = cur->right->key;
						if(cur->right->right == 0)
						{
							delete cur->right;
							cur->right = 0;
						}
						else
							cur->right = cur->right->right;
					}

				}
				if(temp->right == 0)
				{
					temp = temp->left;
					if(temp->right != 0)
					{
						while(temp->right != 0)
						{
							temp = temp->right;
						}
						cur->key = temp->key;
						temp->parent->right = 0;
						delete temp;
					}
					else 
					{
						cur->key = cur->left->key;
						if(cur->left->left == 0)
						{
							delete cur->left;
							cur->left = 0;
						}
						else
							cur->left = cur->left->left;

					}
				}
			}
			else
			{
				Node *cur1 = cur->parent;
				if(cur->right != 0 && cur->left == 0)
				{
					Node *cur2 = cur->right;
					if(cur1->key > cur2->key)
					{
						delete cur;
						cur1->left = cur2;
					}

					else
					{
						delete cur;
						cur1->right = cur2;
					}
				}

				if(cur->right == 0 && cur->left != 0)
				{
					Node *cur3 = cur->left;
					if(cur1->key > cur3->key)
					{
						delete cur;
						cur1->left = cur3;
					}

					else
					{
						delete cur;
						cur1->right = cur3;
					}
				}
			}
		}
	}
}

void BinaryTree::delTree(Node *root)
{
	if (root)
	{
		if (root->right)
			delTree(root->left);
		if (root->left)
			delTree(root->right);
		delete root;
	}
}

int BinaryTree::getcount1()
{
	return count1;
}

void BinaryTree::amount(Node *cur)
{
	if(root)
	{
		if(cur->right)
		{
			count1++;
			amount(cur->right);
		}

		if(cur->left)
		{
			count1++;
			amount(cur->left);
		}

		else return;
	}
	else count1 = 0;
}

int BinaryTree::getamount()
{
	this->amount(this->getRoot());
	return count1;
}

void BinaryTree::array(Node *cur)
{
	if(cur)
	{
		array(cur->left);
		arr[size++] = cur->value;
		array(cur->right);
	}
}

void BinaryTree::setarray()
{
	this->array(this->getRoot());
}

string BinaryTree::getArri(int i)
{
	return arr[i];
}
