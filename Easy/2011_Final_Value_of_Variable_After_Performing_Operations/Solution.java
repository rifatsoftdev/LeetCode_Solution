import java.util.*;


public class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int ans = 0;

        for (String operation : operations) {
            if (operation.equals("++X") || operation.equals("X++")) {
                ans++;
            } else if (operation.equals("--X") || operation.equals("X--")) {
                ans--;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String[] operations1 = {"--X", "X++", "X++"};
        int result1 = solution.finalValueAfterOperations(operations1);
        System.out.println(result1);

        // test cases 2
        String[] operations2 = {"++X", "++X", "X++"};
        int result2 = solution.finalValueAfterOperations(operations2);
        System.out.println(result2);

        // test cases 3
        String[] operations3 = {"X++", "++X", "--X", "X--"};
        int result3 = solution.finalValueAfterOperations(operations3);
        System.out.println(result3);
    }
}