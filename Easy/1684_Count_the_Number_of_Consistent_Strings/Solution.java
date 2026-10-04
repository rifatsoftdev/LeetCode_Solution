import java.util.*;


public class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        boolean[] arr = new boolean[26];

        for (int i = 0; i < allowed.length(); i++) {
            arr[allowed.charAt(i) - 'a'] = true;
        }

        int result = 0;

        for (String s: words) {
            Boolean flag = true;

            for (char c : s.toCharArray()) {
                if (!arr[c - 'a']) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                result++;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String allowed1 = "ab";
        String[] words1 = {"ad","bd","aaab","baa","badab"};
        System.out.println(solution.countConsistentStrings(allowed1, words1));

        // test cases 2
        String allowed2 = "abc";
        String[] words2 = {"a","b","c","ab","ac","bc","abc"};
        System.out.println(solution.countConsistentStrings(allowed2, words2));

        // test cases 3
        String allowed3 = "cad";
        String[] words3 = {"cc","acd","b","ba","bac","bad","ac","d"};
        System.out.println(solution.countConsistentStrings(allowed3, words3));
        
        
    }
}