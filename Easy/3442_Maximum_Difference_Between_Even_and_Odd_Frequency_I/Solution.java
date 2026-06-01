

public class Solution {
    public int maxDifference(String s) {
        int[] freq = new int[26];

        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        int maxOdd = Integer.MIN_VALUE;
        int minEven = Integer.MAX_VALUE;

        for (int f : freq) {
            if (f > 0) {
                if (f % 2 != 0) {
                    maxOdd = Math.max(maxOdd, f);
                } else {
                    minEven = Math.min(minEven, f);
                }
            }
        }

        return maxOdd - minEven;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String s1 = "aaaaabbc";
        System.out.println(solution.maxDifference(s1)); // Expected: 3 (5 - 2)
        
        // test cases 2
        String s2 = "abcabcab";
        System.out.println(solution.maxDifference(s2)); // Expected: 1 (3 - 2)
        
    }
}