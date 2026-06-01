import java.util.Arrays;


public class Solution {
    public int[] separateDigits(int[] nums) {
        StringBuilder sb = new StringBuilder();
        
        for (int num : nums) {
            sb.append(num);
        }
        
        String str = sb.toString();
        int[] result = new int[str.length()];

        for (int i = 0; i < str.length(); i++) {
            result[i] = str.charAt(i) - '0';
        }

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] result1 = solution.separateDigits(new int[]{13, 25, 73, 77});
        System.out.println(Arrays.toString(result1));

        // test cases 2
        int[] result2 = solution.separateDigits(new int[]{7, 1, 3, 9});
        System.out.println(Arrays.toString(result2));
    }
}