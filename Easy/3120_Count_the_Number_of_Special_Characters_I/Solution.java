import java.util.HashSet;
import java.util.Set;


public class Solution {
    public int numberOfSpecialChars(String word) {
        Set<Character> chars = new HashSet<>();
        int count = 0;

        for (char c : word.toCharArray()) {
            chars.add(c);
        }
       
        for (char c : chars) {
            if (Character.isUpperCase(c) && chars.contains(Character.toLowerCase(c))) {
                count++;
            }
        }

        return count;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.numberOfSpecialChars("aaAbcBC"));

        // test cases 2
        System.out.println(solution.numberOfSpecialChars("abc"));
        
        // test cases 3
        System.out.println(solution.numberOfSpecialChars("abBCab"));
    }
}