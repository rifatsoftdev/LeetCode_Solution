import java.util.Stack;


public class Solution {
    public String makeGood(String s) {
        int n = s.length();
        Stack<Character> st = new Stack<>();

        for (int i = 0; i < n; i++) {
            if (!st.empty()) {
                char top = st.peek();

                if (Math.abs(s.charAt(i) - top) == 32) {
                    st.pop();
                } else {
                    st.push(s.charAt(i));
                }
            } else {
                st.push(s.charAt(i));
            }
        }

        String ans = "";

        while (!st.empty()) {
            char c = st.peek();
            st.pop();
            ans =  c + ans;
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.makeGood("leEeetcode"));

        // test cases 2
        System.out.println(solution.makeGood("abBAcC"));

        // test cases 3
        System.out.println(solution.makeGood("s"));
        
    }
}