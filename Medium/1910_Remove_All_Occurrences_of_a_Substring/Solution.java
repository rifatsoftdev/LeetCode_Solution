import java.util.*;


public class Solution {
    public String removeOccurrences(String s, String part) {
        while (s.contains(part)) {
            int pos = s.indexOf(part);
            s = s.substring(0, pos) + s.substring(pos + part.length());
        }

        return s;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String s1 = "daabcbaabcbc";
        String part1 = "abc";
        System.out.println(solution.removeOccurrences(s1, part1));

        // test cases 2
        String s2 = "axxxxyyyyb";
        String part2 = "xy";
        System.out.println(solution.removeOccurrences(s2, part2));
        
        
    }
}