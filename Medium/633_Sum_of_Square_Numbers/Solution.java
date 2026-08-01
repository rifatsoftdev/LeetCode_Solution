


public class Solution {
    public boolean judgeSquareSum(int c) {
        long left = 0;
        long right = (long) Math.sqrt(c);
        
        while (left <= right) {
            long sum = left * left + right * right;
            if (sum == c) return true;
            if (sum < c) left++;
            else right--;
        }
        
        return false;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.judgeSquareSum(5));   // true
        
        // test cases 2
        System.out.println(solution.judgeSquareSum(3));   // false
    }
}