#include<iostream>
using namespace std;

struct Node{
	int data;
	Node * next;
	Node();
};
Node::Node(){
	data = 0;
	next= NULL;
}



class Stack_LinkedList
{
	Node *top ;
public:
	Stack_LinkedList();
	~Stack_LinkedList();
	void push(int);
	int pop ();
	
};

Stack_LinkedList::Stack_LinkedList(){
	top = NULL;
	
}


void Stack_LinkedList ::push(int x)
{
 	Node * newNode = new Node;
 	newNode ->data = x;
 	newNode->next = top;
 	top = newNode;

}

int Stack_LinkedList::pop()
{
   int x = -1;
        if (top == NULL) 
        {
            cout << "Stack is empty" << endl;
        }
        else 
        {
            x = top->data;
         
            top = top->next;
           
        }
        return x;


}


Stack_LinkedList::~Stack_LinkedList(){

}


int main ()
{
	Stack_LinkedList s;
	s.push(1); 
	s.push(2);
	s.push(3);
	cout<<s.pop();
	cout<<s.pop();
	cout<<s.pop();
}

