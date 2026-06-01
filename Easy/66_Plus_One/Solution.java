


class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 0;
        int n = digits.length;

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                digits[i] += 1;
            } else {
                digits[i] += carry;
            }

            if (digits[i] == 10) {
                digits[i] = 0;
                carry = 1;
            } else {
                carry = 0;
            }
        }

        if (carry == 1) {
            int[] newDigits = new int[n + 1];
            newDigits[0] = 1;
            System.arraycopy(digits, 0, newDigits, 1, n);
            return newDigits;
        }

        return digits;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] digits1 = {1, 2, 3};
        int[] result1 = solution.plusOne(digits1);
        System.out.println(result1);

        // test cases 2
        int[] digits2 = {4, 3, 2, 1};
        int[] result2 = solution.plusOne(digits2);
        System.out.println(result2);

        // test cases 3
        int[] digits3 = {9};
        int[] result3 = solution.plusOne(digits3);
        System.out.println(result3);
        
    }
}
