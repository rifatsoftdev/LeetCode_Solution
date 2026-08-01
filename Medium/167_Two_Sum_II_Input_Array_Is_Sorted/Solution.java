


public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int left = 0;
        int right = numbers.length - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return new int[]{left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return new int[0];
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] numbers1 = {2, 7, 11, 15};
        int target1 = 9;
        System.out.println(java.util.Arrays.toString(solution.twoSum(numbers1, target1)));

        // test cases 2
        int[] numbers2 = {2, 3, 4};
        int target2 = 6;
        System.out.println(java.util.Arrays.toString(solution.twoSum(numbers2, target2)));

        // test cases 3
        int[] numbers3 = {-1, 0};
        int target3 = -1;
        System.out.println(java.util.Arrays.toString(solution.twoSum(numbers3, target3)));
    }
}