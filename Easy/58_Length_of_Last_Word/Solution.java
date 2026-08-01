

public class Solution {
    public int lengthOfLastWord(String s) {
        String ans = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) != ' ') {
                ans = s.charAt(i) + ans;
            } else if (!ans.isEmpty()) {
                break;
            }
        }
        return ans.length();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test cases 1
        System.out.println(solution.lengthOfLastWord("Hello World"));

        // Test cases 2
        System.out.println(solution.lengthOfLastWord("   fly me   to   the moon  "));

        // Test cases 3
        System.out.println(solution.lengthOfLastWord("luffy is still joyboy"));
    }
}