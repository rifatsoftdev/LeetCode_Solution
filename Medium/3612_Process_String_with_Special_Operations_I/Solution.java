


public class Solution {
    public String processStr(String s) {
        StringBuilder result = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (c == '*') {
                // Remove the last character
                if (result.length() > 0) {
                    result.deleteCharAt(result.length() - 1);
                }
            } else if (c == '#') {
                // Duplicate
                if (result.length() > 0) {
                    result.append(result.toString());
                }
            } else if (c == '%') {
                // Reverse
                result.reverse();
            } else {
                // Append
                result.append(c);
            }
        }

        return result.toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String s1 = "a#b%*";
        System.out.println(solution.processStr(s1));

        // test cases 2
        String s2 = "z*#";
        System.out.println(solution.processStr(s2));
        
    }
}