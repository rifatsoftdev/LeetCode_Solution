import java.util.*;


public class Solution {
    public int smallestNumber(int n, int t) {
        int current = n;

        while (true) {
            int product = 1;
            int temp = current;

            while (temp > 0) {
                product *= (temp % 10);
                temp /= 10;
            }

            if (product % t == 0) {
                return current;
            }

            current++;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.smallestNumber(10, 2));

        // test cases 2
        System.out.println(solution.smallestNumber(15, 3));
        
    }
}