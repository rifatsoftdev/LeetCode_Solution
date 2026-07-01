


public class Solution {
    public int largestAltitude(int[] gain) {
        int maxNum = 0;
        int prefixSum = 0;

        for (int i = 0; i < gain.length; i++) {
            prefixSum += gain[i];
            maxNum = Math.max(maxNum, prefixSum);
        }

        return maxNum;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] gain1 = {-5,1,5,0,-7};
        System.out.println(solution.largestAltitude(gain1));

        // test cases 2
        int[] gain2 = {-4,-3,-2,-1,4,3,2};
        System.out.println(solution.largestAltitude(gain2));
        
    }
}