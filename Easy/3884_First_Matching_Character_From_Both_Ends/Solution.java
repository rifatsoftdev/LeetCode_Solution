import java.util.*;


public class Solution {
    public int firstMatchingIndex(String s) {
        int left = 0;
        int right = s.length() - 1;

        while (left <= right) {
            if (s.charAt(left) == s.charAt(right)) {
                return left;
            }

            left++;
            right--;
        }

        return -1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String s1 = "abcacbd";
        System.out.println(solution.firstMatchingIndex(s1));

        // test cases 2
        String s2 = "abc";
        System.out.println(solution.firstMatchingIndex(s2));

        // test cases 3
        String s3 = "abcdab";
        System.out.println(solution.firstMatchingIndex(s3));
        
        
    }
}