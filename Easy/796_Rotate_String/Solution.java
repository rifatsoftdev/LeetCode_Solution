

public class Solution {
    public boolean rotateString(String s, String goal) {
        int n = s.length();

        for (int i = 0; i < n; i++) {
            String rotate = s.substring(i) + s.substring(0, i);

            if (rotate.equals(goal)) return true;
        }

        return false;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.rotateString("abcde", "cdeab")); // Output: true

        // test cases 2
        System.out.println(solution.rotateString("abcde", "abced")); // Output: false
    }
}