import java.util.*;


public class Solution {
    public boolean checkDivisibility(int n) {
        int sum = 0;
        int pro = 1;
        int m = n;

        while (n != 0) {
            int d = n % 10;

            sum += d;
            pro *= d;

            n /= 10;
        }
        
        return m % (sum + pro) == 0;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.checkDivisibility(99));

        // test cases 2
        System.out.println(solution.checkDivisibility(23));
        
    }
}