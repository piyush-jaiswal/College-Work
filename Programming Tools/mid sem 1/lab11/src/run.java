import java.util.Scanner;
import stringCheck.checkPalindrome;

public class run
{
	public static void main(String[] args)
	{
		int ch = 0;
		
		while(ch != 1)
		{
			Scanner sc = new Scanner(System.in);
			System.out.println("Enter the string");
			String a = sc.nextLine();
		
			boolean ans = checkPalindrome.isPalindrome(a);
			System.out.println("Are they palindrome?: " + ans);
			System.out.println("Press 1 to exit or any other no. to continue");
			ch = sc.nextInt();
		}
	}
}
