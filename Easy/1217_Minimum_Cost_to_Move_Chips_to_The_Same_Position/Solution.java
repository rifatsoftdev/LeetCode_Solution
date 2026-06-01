

public class Solution {
    public int minCostToMoveChips(int[] position) {
        int evenCount = 0;
        int oddCount = 0;

        for (int chip : position) {
            if (chip % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }

        return Math.min(evenCount, oddCount);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] position1 = {1, 2, 3};
        System.out.println(solution.minCostToMoveChips(position1)); // Expected output: 1
        
        // test cases 2
        int[] position2 = {2, 2, 2, 3, 3};
        System.out.println(solution.minCostToMoveChips(position2)); // Expected output: 2

        // test cases 3
        int[] position3 = {1, 1000000000};
        System.out.println(solution.minCostToMoveChips(position3)); // Expected output: 1
        
    }
}