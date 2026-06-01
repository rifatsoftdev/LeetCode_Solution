

public class Solution {
    Boolean isPrime(int n) {
        if (n <= 1) return false;

        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }

        return true;
    }

    int maximumPrimeDifference(int[] nums) {
        
        int left_prime = -1;
        int right_prime = -1;

        for (int i = 0; i < nums.length; i++) {
            if (isPrime(nums[i])) {
                left_prime = i;
                break;
            }
        }

        for (int i = nums.length - 1; i >= 0; i--) {
            if (isPrime(nums[i])) {
                right_prime = i;
                break;
            }
        }
        
        return right_prime - left_prime;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        
        // test cases 1
        int[] nums1 = {4,2,9,5,3};
        System.out.println(solution.maximumPrimeDifference(nums1)); // Output: 3

        // test cases 2
        int[] nums2 = {4,8,2,8};
        System.out.println(solution.maximumPrimeDifference(nums2)); // Output: 0
        
    }
}