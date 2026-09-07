import java.util.*;


class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();

        for (int num : nums1) {
            set1.add(num);
        }

        for (int num : nums2) {
            set2.add(num);
        }

        List<Integer> ans1 = new ArrayList<>();
        List<Integer> ans2 = new ArrayList<>();

        for (int num : set1) {
            if (!set2.contains(num)) {
                ans1.add(num);
            }
        }

        for (int num : set2) {
            if (!set1.contains(num)) {
                ans2.add(num);
            }
        }

        List<List<Integer>> result = new ArrayList<>();
        result.add(ans1);
        result.add(ans2);

        return result;
    }

    private static void printVec2D(List<List<Integer>> vec2D) {
        System.out.print("[");
        for (int i = 0; i < vec2D.size(); i++) {
            System.out.print("[");
            for (int j = 0; j < vec2D.get(i).size(); j++) {
                System.out.print(vec2D.get(i).get(j));
                if (j < vec2D.get(i).size() - 1) {
                    System.out.print(", ");
                }
            }
            System.out.print("]");
            if (i < vec2D.size() - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1, 2, 3};
        int[] nums2 = {2, 4, 6};
        List<List<Integer>> result = solution.findDifference(nums1, nums2);
        printVec2D(result);

        // test cases 2
        int[] nums3 = {1, 2, 3, 3};
        int[] nums4 = {1, 1, 2, 2};
        result = solution.findDifference(nums3, nums4);
        printVec2D(result);
        
    }
}