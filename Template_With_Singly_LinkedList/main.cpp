#include<iostream>
#include"list.hh"
using namespace std;

int main()
{
	int dec;
	cout<<"Enter which type of data you want to perform tasks on "<<endl;
	cout<<"Enter 1 for integer"<<endl;
	cout<<"Eneter 2 for Character"<<endl;
	cin>>dec;
if (dec ==1)
{
	

	List<int> list_int;
	int s ,a;
		for (int i = 0; i < 5; i++)
		{
		cout << "\nEnter data:";
		cin >> s;
		list_int.add(s);
		}
		cout<<"Do you want to insert data after any element(y/n)";
		char c;
		cin>>c;
		if (c=='y')
		{
			cout << "\nEnter an elemet you want to insert after another elemet:";
	cin >> s;
	cout << "\nEnter element after which you want to insert it:";
	cin >> a;
	cout << endl;
		if (list_int.insert(s,a))
		{
		cout << "\t\tData entered successfully\n";
		}
		else
		{
		cout << "\t Invalid Entry \n";
		}
		
	
	
	for (int i = 0; i < list_int.getSize(); i++)
	{
		cout << "At " << i + 1 << " index data is:" << list_int.get(i) << endl;
	}
		}
		cout<<"Do you want to delete any data (y/n)";
		cin>>c;
		if (c=='y')
	{
	cout << "\nEnter data you want to delete:";
	cin >> s;
	list_int.remove(s);
	cout << "\n Updated Data:" << endl;
		

		for (int i = 0; i < list_int.getSize(); i++)
		{
		cout << "At " << i + 1 << " index data is:" << list_int.get(i) << endl;
		}
	}
	list_int.clear();
	cout<<"\t\tAll Data Cleared"<<endl;
	
	}

else if(dec == 2){



List<char> list_char;
	char s ,a;
		for (int i = 0; i < 5; i++)
		{
		cout << "\nEnter data:";
		cin >> s;
		list_char.add(s);
		}
		cout<<"Do you want to insert data after any element(y/n)";
		char c;
		cin>>c;
		if (c=='y')
		{
	cout << "\nEnter an elemet you want to insert after another elemet:";
	cin >> s;
	cout << "\nEnter element after which you want to insert it:";
	cin >> a;
	cout << endl;
		if (list_char.insert(s,a))
		{
		cout << "\t\tData entered successfully\n";
		}
		else
		{
		cout << "\tInvalid Entry\n";
		}
	for (int i = 0; i < list_char.getSize(); i++)
	{
		cout << "At " << i + 1 << " index data is:" << list_char.get(i) << endl;
	}
		}
		cout<<"Do you want to delete any data (y/n)";
		cin>>c;
		if (c=='y')
	{
	cout << "\nEnter data you want to delete:";
	cin >> s;
	list_char.remove(s);
	cout << "\n Updated data:" << endl;
		for (int i = 0; i < list_char.getSize(); i++)
		{
		cout << "At " << i + 1 << " index data is:" << list_char.get(i) << endl;
		}
	}
	list_char.clear();
	cout<<"\t\tAll Data Cleared"<<endl;
	
}
else
	cout<<"Invalid Input";
return 0;
}