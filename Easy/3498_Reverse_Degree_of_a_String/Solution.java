import java.util.*;


public class Solution {
    public int reverseDegree(String s) {
        int degree = 0;

        for (int i = 0; i < s.length(); i++) {
            int rev = 26 - (s.charAt(i) - 'a' + 1) + 1;
            degree += (rev * (i + 1));
        }

        return degree;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String s1 = "abc";
        int result1 = solution.reverseDegree(s1);
        System.out.println(result1);

        // test cases 2
        String s2 = "zaza";
        int result2 = solution.reverseDegree(s2);
        System.out.println(result2);
        
    }
}