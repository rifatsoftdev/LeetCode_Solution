import java.util.*;


public class Solution {
    public int digitFrequencyScore(int n) {
        int ans = 0;

        while (n != 0) {
            int d = n % 10;
            ans += d;
            n /= 10;
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.digitFrequencyScore(122));

        // test cases 2
        System.out.println(solution.digitFrequencyScore(101));
        
    }
}