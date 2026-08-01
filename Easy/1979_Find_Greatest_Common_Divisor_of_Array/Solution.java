import java.util.Arrays;


class Solution {
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public int findGCD(int[] nums) {
        Arrays.sort(nums);

        return gcd(nums[0], nums[nums.length - 1]);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums = {2,5,6,9,10};
        System.out.println(solution.findGCD(nums));

        // test cases 2
        int[] nums2 = {7,5,6,8,3};
        System.out.println(solution.findGCD(nums2));

        // test cases 3
        int[] nums3 = {3,3};
        System.out.println(solution.findGCD(nums3));
    }
}