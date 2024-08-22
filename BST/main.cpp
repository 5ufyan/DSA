#include"header.hh"

int main ()
{
	int a;
IntBinaryTree tree;

for (int i = 0; i < 5; ++i)
{
	cout<<"Enter any number"<<endl;
	cin>>a;
	tree.insertNode(a);
}
	cout << "Done.\n";
	cout << "Inorder traversal:\n";
	tree.showNodesInOrder();
	
	cout<<"What do you want to search "<<endl;
	cin>>a;
	if (tree.searchNode(a))
		cout << a<<" is in the tree.\n";
	else
		cout << a<< " was not found in the tree.\n";

	cout<<"What do you want to delete "<<endl;
	cin>>a;
	tree.remove(a);

	cout << "Remaining number are:\n";
	tree.showNodesInOrder();
}

