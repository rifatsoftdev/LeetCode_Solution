import java.util.*;


class Solution {
    public int countCommas(int n) {
        int ans = n - 999;

        if (ans < 0) {
            return 0;
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int n1 = 1002;
        int result1 = solution.countCommas(n1);
        System.out.println(result1);

        // test cases 2
        int n2 = 999;
        int result2 = solution.countCommas(n2);
        System.out.println(result2);
        
        
    }
}