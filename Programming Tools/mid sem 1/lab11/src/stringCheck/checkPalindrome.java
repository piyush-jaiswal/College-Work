package stringCheck;

public class checkPalindrome {

	public static boolean isPalindrome(String a)
	{
		int length = a.length();
		for(int i = 0; i < length; i++)
		{
			if(a.charAt(i) != a.charAt(length - 1 - i))
				return false;
		}
		return true;
	}
}
