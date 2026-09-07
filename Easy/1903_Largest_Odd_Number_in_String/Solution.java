


public class Solution {
    public String largestOddNumber(String num) {
        String result = "";

        for (int i = num.length() - 1; i >= 0; i--) {
            if ((num.charAt(i) - '0') % 2 == 1) {
                result = num.substring(0, i + 1);
                break;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String num1 = "52";
        String result1 = solution.largestOddNumber(num1);
        System.out.println(result1); // Expected output: "5"

        // test cases 2
        String num2 = "4206";
        String result2 = solution.largestOddNumber(num2);
        System.out.println(result2); // Expected output: ""

        // test cases 3
        String num3 = "35427";
        String result3 = solution.largestOddNumber(num3);
        System.out.println(result3); // Expected output: "35427"

    }
}