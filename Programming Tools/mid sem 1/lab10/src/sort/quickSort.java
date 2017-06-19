package sort;
//import java.util.Scanner;

public class quickSort {
	
	static void swap(int ar[], int pos1, int pos2)
	{
		int temp = ar[pos1];
		ar[pos1] = ar[pos2];
		ar[pos2] = temp;
	}
	
	static int partition(int ar[], int low, int high)
	{
		int i,pivot_pos,toBeInserted;
		pivot_pos = (low + high) / 2;
		swap(ar, low, pivot_pos);
		toBeInserted = low;
		pivot_pos = low;
		
		for(i=low+1; i<high; i++)
		{
			if(ar[i] < ar[pivot_pos])
			{
				swap(ar, i, toBeInserted);
				toBeInserted = toBeInserted+1;
				pivot_pos = i;
			}
		}
		swap(ar, toBeInserted, pivot_pos);
		return toBeInserted;
	}
	
	public static void sort(int ar[], int low, int high)
	{
		if(low < high)
		{
			int p = partition(ar, low, high);
			sort(ar, 0, p);
			sort(ar, p+1, high);
		}
	}

	/*public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n,i;
		
		System.out.println("Enter the size");
		n = sc.nextInt();
		int ar[] = new int[n];
		System.out.println("Enter the elements");
		for(i=0; i<n; i++)
			ar[i] = sc.nextInt();
		quickSort ob = new quickSort();
		ob.sort(ar, 0, n);
		ob.print(ar);
	}*/

}
