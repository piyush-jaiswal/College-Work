#include<iostream>
#include<conio.h>

using namespace std;

	//step 2, this method processed the action to print out all possible combination of elements with fixed size
	//as we discussed in the slide, we need three additional variables to keep track of status
	//boolean array to know whether printed out or not, 
	//start is the start index to be printed to prevent duplicates
	//remain is keeping track of how many remaining elements to be processed for the subset action
    void PrintSubSet(int nums[], bool ifPrint[], int start, int remain, int n)
	{
		//firstly if remain==0, we done!
		if(remain == 0)
		{
			cout<<"{";
			//check each ifPrint status to decide print or not
			for(int i=0; i<n;i++)
			{
				if(ifPrint[i])
					cout<<nums[i]<<",";
			}
			cout<<"}\n";//format the output of one subset one line
		}
		else
		{
			//now is the key recursive part, we need process char by char from the start position until end
			//before that, we need determine whether we proceed or not to check if start+remain>nums.length
			if(start+remain>n)//not possible even if all remaining element to be used
				;
			else
			{
				for(int i=start; i<n;i++)
				{
					//now before we come to recursive part we have to make sure this position is not used
					if(!ifPrint[i])
					{
						//now assign its value to true as used indicator
						ifPrint[i] = true;
						//recursive call!
						PrintSubSet(nums, ifPrint, i+1, remain-1, n);//notice the update of start index and remain count
						//another key point! set the position back to false and proceed from next element
						ifPrint[i] = false;
					}
				}
			}
		}
	}


//step 1, decide how many elements in a sub-array to be printed
	 void PrintSubSet(int nums[], int n)
	{
		//now we process the first step
		int j;
		for(int i=0; i<=n; i++)//subset length could vary from 0 to nums.length
		{
			bool ifPrint[n];
			for(int j=0; j<n; j++)
				ifPrint[j] = false;
			PrintSubSet(nums, ifPrint, 0, i, n);//start from 0th index, and the size varies for the loop
		}
	}


	//lastly let's create a test case
	int main()
	{
		int nums[] = {1,2,3,4,5}, n=5;
		PrintSubSet(nums, n);
		getch();
		return 0;
	}
