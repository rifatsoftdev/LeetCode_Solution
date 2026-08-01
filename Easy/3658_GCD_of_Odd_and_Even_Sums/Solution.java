


public class Solution {
    public int gcdOfOddEvenSums(int n) {
        int oddSum = 0, evenSum = 0;

        for (int i = 1; i <= n*2; i += 2) {
            oddSum += i;
        }

        for (int i = 2; i <= n*2; i += 2) {
            evenSum += i;
        }

        while (evenSum != 0) {
            int temp = oddSum % evenSum;
            oddSum = evenSum;
            evenSum = temp;
        }

        return oddSum;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.gcdOfOddEvenSums(4)); // Output: 4
        
        // test cases 2
        System.out.println(solution.gcdOfOddEvenSums(5)); // Output: 5
        
    }
}