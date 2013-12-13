#include "Dictionary.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	BinaryTree temp;
	BinaryTree *cur = &temp;
	
	int n;
	cout << "enter amount of elements" << endl;
	cin >> n;

	cout << "enter elements" << endl;
	for(int i = 0; i < n; i++)
	{
		int key;
		string value;
		cout << "enter string: ";
		cin >> value;
		cout << endl;
		cout << "enter number: ";
		cin >> key;
		cout << endl;
		cur->add(key, value);
	}
	
	cur->print();

	cur->getamount();
	
	cout << cur->getcount1() << endl;

	cur->setarray();
	cout << "array of strings:" << endl;
	for(int j = 0; j < temp.getsize(); j++)
	{
		cout << temp.getArri(j) << " ";
	}

	system("pause");
	return 0;
}