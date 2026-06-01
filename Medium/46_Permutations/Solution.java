import java.util.ArrayList;
import java.util.List;


public class Solution {
    private static void getPermute(int[] nums, List<Integer> ds, boolean[] isValid, List<List<Integer>> ans) {
        if (ds.size() == nums.length) {
            List<Integer> list = new ArrayList<>();

            for (int i = 0; i < ds.size(); i++) {
                list.add(ds.get(i));
            }
            ans.add(list);
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (isValid[i] == false) {
                ds.add(nums[i]);
                isValid[i] = true;
                getPermute(nums, ds, isValid, ans);
                isValid[i] = false;
                ds.remove(ds.size() - 1);
            }
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        List<Integer> ds = new ArrayList<>();
        boolean[] isValid = new boolean[nums.length];
        List<List<Integer>> ans = new ArrayList<>();
        
        getPermute(nums, ds, isValid, ans);
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1, 2, 3};
        List<List<Integer>> ans1 = solution.permute(nums1);
        for (List<Integer> l : ans1) {
            System.out.println(l);
        }

        // test cases 2
        int[] nums2 = {1, 2, 3};
        List<List<Integer>> ans2 = solution.permute(nums2);
        for (List<Integer> l : ans2) {
            System.out.println(l);
        }
    }
}
