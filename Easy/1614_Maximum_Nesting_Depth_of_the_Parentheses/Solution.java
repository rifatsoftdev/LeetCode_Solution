import java.util.*;


public class Solution {
    public int maxDepth(String s) {
        int depth = 0;
        int result = 0;

        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                depth++;
            } else if (ch == ')') {
                depth--;
            }

            result = Math.max(result, depth);
        }

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String s1 = "(1+(2*3)+((8)/4))+1";
        System.out.println(solution.maxDepth(s1));

        // test cases 2
        String s2 = "(1)+((2))+(((3)))";
        System.out.println(solution.maxDepth(s2));

        // test cases 3
        String s3 = "()(())((()()))";
        System.out.println(solution.maxDepth(s3));
        
        
    }
}