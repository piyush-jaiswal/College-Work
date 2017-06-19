import sort.quickSort;
import java.util.Scanner;

public class run
{
	static void print(int ar[])
	{
		for(int i = 0; i < ar.length; i++)
			System.out.print(ar[i] + "\t");
		System.out.println();
	}	
	
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int n,i;
		
		System.out.println("Enter the size");
		n = sc.nextInt();
		int ar[] = new int[n];
		System.out.println("Enter the elements");
		for(i=0; i<n; i++)
			ar[i] = sc.nextInt();
		quickSort.sort(ar, 0, n);
		print(ar);
	}
}
