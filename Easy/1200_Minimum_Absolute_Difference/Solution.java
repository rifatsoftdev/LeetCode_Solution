import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;


public class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int minDiff = Integer.MAX_VALUE;
        List<List<Integer>> result = new ArrayList<>();

        for (int i = 1; i < arr.length; i++) {
            int diff = arr[i] - arr[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result.clear();
                result.add(Arrays.asList(arr[i - 1], arr[i]));
            } else if (diff == minDiff) {
                result.add(Arrays.asList(arr[i - 1], arr[i]));
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        List<List<Integer>> result1 = solution.minimumAbsDifference(new int[]{4, 2, 1, 3});
        System.out.println(result1);

        // test cases 2
        List<List<Integer>> result2 = solution.minimumAbsDifference(new int[]{1, 3, 6, 10, 15});
        System.out.println(result2);

        // test cases 3
        List<List<Integer>> result3 = solution.minimumAbsDifference(new int[]{3, 8, -10, 23, 19, -4, -14, 27});
        System.out.println(result3);

    }
}