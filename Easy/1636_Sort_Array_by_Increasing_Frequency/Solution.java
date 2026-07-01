import java.util.*;


class Solution {
    public int[] frequencySort(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();

        for (int x : nums) {
            freq.put(x, freq.getOrDefault(x, 0) + 1);
        }

        Integer[] arr = Arrays.stream(nums).boxed().toArray(Integer[]::new);

        Arrays.sort(arr, (a, b) -> {
            if (!freq.get(a).equals(freq.get(b))) {
                return freq.get(a) - freq.get(b); // frequency ascending
            }
            return b - a; // value descending
        });

        for (int i = 0; i < nums.length; i++) {
            nums[i] = arr[i];
        }

        return nums;
    }

    private static void printArr(int[] arr) {
        System.out.println(Arrays.toString(arr));
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1,1,2,2,2,3};
        int[] result1 = solution.frequencySort(nums1);
        printArr(result1);

        // test cases 2
        int[] nums2 = {2,3,1,3,2};
        int[] result2 = solution.frequencySort(nums2);
        printArr(result2);

        // test cases 2
        int[] nums3 = {-1,1,-6,4,5,-6,1,4,1};
        int[] result3 = solution.frequencySort(nums3);
        printArr(result3);
        
    }
}