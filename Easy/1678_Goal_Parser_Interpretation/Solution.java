


public class Solution {
    public String interpret(String command) {
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < command.length(); ++i) {
            if (command.charAt(i) == 'G') {
                result.append('G');
            } else if (command.charAt(i) == '(' && i + 1 < command.length() && command.charAt(i + 1) == ')') {
                result.append("o");
                i++;
            } else if (command.charAt(i) == '(' && i + 3 < command.length() && command.charAt(i + 1) == 'a' && command.charAt(i + 2) == 'l' && command.charAt(i + 3) == ')') {
                result.append("al");
                i += 3;
            }
        }

        return result.toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.interpret("G()(al)")); // Output: Goal
        
        // test cases 2
        System.out.println(solution.interpret("G()()()()(al)")); // Output: Gooooal

        // test cases 3
        System.out.println(solution.interpret("(al)G(al)()()G")); // Output: alGalooG
    }
}