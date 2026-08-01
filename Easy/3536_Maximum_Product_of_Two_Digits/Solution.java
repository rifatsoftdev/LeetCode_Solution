


public class Solution {
    public int maxProduct(int n) {
        int firstLarge = 0;
        int secondLarge = 0;

        while (n != 0) {
            int digit = n % 10;

            if (digit > firstLarge) {
                secondLarge = firstLarge;
                firstLarge = digit;
            }
            else if (digit > secondLarge) {
                secondLarge = digit;
            }
            
            n /= 10;
        }

        return firstLarge * secondLarge;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int n1 = 31;
        System.out.println(solution.maxProduct(n1));

        // test cases 2
        int n2 = 22;
        System.out.println(solution.maxProduct(n2));

        int n3 = 124;
        System.out.println(solution.maxProduct(n3));
        
    }
}