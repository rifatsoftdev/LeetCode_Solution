import java.util.*;


public class Solution {
    public long countCommas(long n) {
        long ans = 0;

        for (long i = 1000; i <= n; i *= 1000) {
            ans += (n - i + 1);
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        long n1 = 1002;
        long result1 = solution.countCommas(n1);
        System.out.println(result1);

        // test cases 2
        long n2 = 998;
        long result2 = solution.countCommas(n2);
        System.out.println(result2);
        
  
    }
}