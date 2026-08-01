import java.util.ArrayDeque;
import java.util.Deque;

public class Solution {
    public String removeStars(String s) {
        Deque<Character> st = new ArrayDeque<>();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '*' && st.size() != 0) {
                st.pop();
            } else if (s.charAt(i) != '*') {
                st.push(s.charAt(i));
            }
        }
        
        StringBuilder sb = new StringBuilder();
        while (!st.isEmpty()) {
            sb.append(st.pop());
        }
        return sb.reverse().toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String s1 = "leet**cod*e";
        System.out.println(solution.removeStars(s1));

        // test cases 2
        String s2 = "erase*****";
        System.out.println(solution.removeStars(s2));
        
    }
}