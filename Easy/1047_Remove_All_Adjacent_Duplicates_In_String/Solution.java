import java.util.ArrayDeque;
import java.util.Deque;


public class Solution {
    public String removeDuplicates(String s) {
        Deque<Character> st = new ArrayDeque<>();

        for (int i = 0; i < s.length(); i++) {
            if (!st.isEmpty() && st.peek() == s.charAt(i)) {
                st.pop();
            } else {
                st.push(s.charAt(i));
            }
        }
        
        StringBuilder result = new StringBuilder();
        
        while (!st.isEmpty()) {
            result.append(st.pop());
        }

        return result.reverse().toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String s1 = "abbaca";
        System.out.println(solution.removeDuplicates(s1));
        
        // test cases 2
        String s2 = "azxxzy";
        System.out.println(solution.removeDuplicates(s2));
        
    }
}