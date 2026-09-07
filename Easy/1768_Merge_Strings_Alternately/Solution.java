import java.util.*;


public class Solution {
    public String mergeAlternately(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        int i = 0, j = 0;
        StringBuilder result = new StringBuilder();

        while (i < n && j < m) {
            result.append(word1.charAt(i++));
            result.append(word2.charAt(j++));
        }

        while (i < n) {
            result.append(word1.charAt(i++));
        }

        while (j < m) {
            result.append(word2.charAt(j++));
        }

        return result.toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String word1 = "abc";
        String word2 = "pqr";
        String result = solution.mergeAlternately(word1, word2);
        System.out.println(result); // Expected: "apbqcr"

        // test cases 2
        word1 = "ab";
        word2 = "pqrs";
        result = solution.mergeAlternately(word1, word2);
        System.out.println(result); // Expected: "apbqcr"

        // test cases 3
        word1 = "abcd";
        word2 = "pq";
        result = solution.mergeAlternately(word1, word2);
        System.out.println(result); // Expected: "apbqcr"

    }
}