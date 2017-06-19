#include <iostream>

using namespace std;

int count = 0;

void swap(string& st, int swapPos, int newPos)
{
	char c = st[swapPos];
	st[swapPos] = st[newPos];
	st[newPos] = c;
}


void permutation(string st, int swapPos)
{
	if(swapPos == st.length() - 1)
	{
		cout << st << endl;
		count ++;
		return;
	}
	
	int length, i;
	length = st.length();
	
	for(i = swapPos; i < length; i++)
	{
		swap(st, swapPos, i);
		permutation(st, swapPos+1);
	}
}


int main()
{
	string s;
	cout << endl << "Enter the string" << endl;
	cin >> s;
	cout << endl << "Permutations" << endl;
	permutation(s, 0);
	cout << endl << "No. of permutations = " << count << endl << endl;
	return 0;
}
