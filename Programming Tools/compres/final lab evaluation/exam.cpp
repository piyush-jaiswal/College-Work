#include <iostream>
#include <fstream>

using namespace std;


typedef struct node
{
	string val;
	struct node *next;
}Node;
Node *start = NULL;


// Make new node
Node* makeNode(string s)
{
	Node *make = new Node();
	make -> val = s;
	make -> next = NULL;
	
	return make;
}


// Insert node at the start of the list
void insert(Node* ins)
{
	ins -> next = start;
	start = ins;
}


// Push the words into the list
void pushWords(ifstream &file)
{
	char ch;
	file.get(ch);
	string temp;
	
	while(file.good())
	{
		if(ch == ',' || ch == '.')
		{
			Node *ins = makeNode(temp);
			insert(ins);
			break;
		}
			
		else if(ch == ' ')
		{
			if(temp != "")
			{
				Node *ins = makeNode(temp);
				insert(ins);
				temp = "";
			}
		}
		
		else
			temp += ch;
			
		file.get(ch);
	}
}


// Pop word from the list
void popWord(ifstream &file)
{
	Node *p = start;
	start = start -> next;
	delete p;
}


// Display the list
void showList()
{
	Node *temp;
	temp = start;
	
	while(temp != NULL)
	{
		cout << temp -> val << " -> ";
		temp = temp -> next;
	}
	cout << "NULL" << endl << endl;
}


int main()
{
	ifstream file("record.txt");
	char ch;
	
	cout << endl;
	while(file.good())
	{
		file.get(ch);
		
		if(ch == '#')
		{
			pushWords(file);
			cout << "Pushing elements in the stack as it encountered a #:" << endl;
			showList();
		}
		
		if(ch == '!')
		{
			popWord(file);
			cout << "Popping element from the stack as it encountered a !:" << endl;
			showList();
		}
	}
	
	
	file.close();
	return 0;
}
