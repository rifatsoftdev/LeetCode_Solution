import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class Solution {
    public long sumAndMultiply(int n) {
        long sum = 0;
        List<Integer> digits = new ArrayList<>();

        while (n > 0) {
            int digit = n % 10;

            if (digit != 0) {
                sum += digit;
                digits.add(digit);
            }

            n /= 10;
        }

        Collections.reverse(digits);
        long product = 0;

        for (int digit : digits) {
            product = product * 10 + digit;
        }

        return sum * product;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.sumAndMultiply(10203004)); // Output: 12340

        // test cases 2
        System.out.println(solution.sumAndMultiply(1000)); // Output: 1
        
    }
}