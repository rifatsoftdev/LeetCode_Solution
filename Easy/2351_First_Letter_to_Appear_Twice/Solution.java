import java.util.*;


public class Solution {
    public char repeatedCharacter(String s) {
        Set<Character> seen = new HashSet<>();

        for (char c : s.toCharArray()) {
            if (seen.contains(c)) {
                return c;
            }
            seen.add(c);
        }

        return '\0';
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String s1 = "abccbaacz";
        System.out.println(solution.repeatedCharacter(s1));

        // test cases 2
        String s2 = "abcdd";
        System.out.println(solution.repeatedCharacter(s2));
        
    }
}