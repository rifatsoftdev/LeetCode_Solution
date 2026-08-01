


public class Solution {
    public int smallestEvenMultiple(int n) {
        if (n % 2 == 0) return n;
        return n * 2;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.smallestEvenMultiple(5));  // Expected: 10
        
        // test cases 2
        System.out.println(solution.smallestEvenMultiple(6));  // Expected: 6
    }
}