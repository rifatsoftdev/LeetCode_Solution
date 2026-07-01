

public class Solution {
    public int findLucky(int[] arr) {
        int[] count = new int[501];

        for (int num : arr) {
            count[num]++;
        }

        int luckyInteger = -1;

        for (int i = 1; i < count.length; i++) {
            if (count[i] == i) {
                luckyInteger = i;
            }
        }

        return luckyInteger;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] arr1 = {2, 2, 3, 4};
        System.out.println(solution.findLucky(arr1)); // Output: 2
        
        // test cases 2
        int[] arr2 = {1, 2, 2, 3, 3, 3};
        System.out.println(solution.findLucky(arr2)); // Output: 3

        // test cases 3
        int[] arr3 = {2, 2, 2, 3, 3};
        System.out.println(solution.findLucky(arr3)); // Output: -1
        
    }
}