import java.util.*;


public class Solution {
    public boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (!Character.isLetterOrDigit(s.charAt(left))) {
                left++;
            } else if (!Character.isLetterOrDigit(s.charAt(right))) {
                right--;
            } else {
                if (Character.toLowerCase(s.charAt(left)) != Character.toLowerCase(s.charAt(right))) {
                    return false;
                }
                else {
                    left++;
                    right--;
                }
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String s1 = "A man, a plan, a canal: Panama";
        System.out.println(solution.isPalindrome(s1));

        // test cases 2
        String s2 = "race a car";
        System.out.println(solution.isPalindrome(s2));

        // test cases 3
        String s3 = " ";
        System.out.println(solution.isPalindrome(s3));
        
        
    }
}