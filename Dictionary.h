#include <string>

using namespace std;

class BinaryTree
{

	struct Node
	{
		int key;
		string value;
		Node *left;
		Node *right;
		Node *parent;
	};

private: 
	Node *root;
	int size;
	string arr[1000];
	int count1;
	void copy(Node *x, Node *xnew);
	void show(Node *root, int level);
	void delTree(Node *root);
	void amount(Node *cur);
	void array(Node *cur);
	Node *getRoot()
	{ return root;}
public:
	BinaryTree();
	~BinaryTree();
	BinaryTree(const BinaryTree&);
	void print();
	void add(int value, string c);
	void search(int value);
	void del(int value);
	void setarray();
	int getamount();
	int getcount1();
	int getsize();
	string getArri(int i);
};