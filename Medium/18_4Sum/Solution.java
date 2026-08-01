import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();

        Arrays.sort(nums);

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2;) {

                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    long sum = (long) nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum < target) {
                        k++;
                    } else if (sum > target) {
                        l--;
                    } else {
                        ans.add(Arrays.asList(nums[i], nums[j], nums[k], nums[l]));

                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }
                }

                j++;
                while (j < n - 2 && nums[j] == nums[j - 1]) j++;
            }
        }

        return ans;
    }

    public void printVec2D(List<List<Integer>> nums) {
        for (List<Integer> row : nums) {
            System.out.println(row);
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1,0,-1,0,-2,2};
        List<List<Integer>> ans1 = solution.fourSum(nums1, 0);
        solution.printVec2D(ans1);

        // test cases 1
        int[] nums2 = {2,2,2,2,2};
        List<List<Integer>> ans2 = solution.fourSum(nums2, 8);
        solution.printVec2D(ans2);
        
    }
}