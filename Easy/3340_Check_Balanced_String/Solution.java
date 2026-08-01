

class Solution {
    public boolean isBalanced(String num) {
        int even_sum = 0;
        int odd_sum = 0;

        for (int i = 0; i < num.length(); i++) {
            int digit = num.charAt(i) - '0';

            if (i % 2 == 0) {
                even_sum += digit;
            } else {
                odd_sum += digit;
            }
        }

        return even_sum == odd_sum;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.isBalanced("1234"));  // Output: False

        // test cases 2
        System.out.println(solution.isBalanced("24123"));  // Output: True
    }
}