

public class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int maxGap = -1;
        int n = s.length();
        char[] charArray = s.toCharArray();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (charArray[i] == charArray[j] && maxGap < j-i) {
                    maxGap = j-i-1;
                }
            }
        }

        return maxGap;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.maxLengthBetweenEqualCharacters("aa"));     // 0

        // test cases 2
        System.out.println(solution.maxLengthBetweenEqualCharacters("abca"));   // 2

        // test cases 3
        System.out.println(solution.maxLengthBetweenEqualCharacters("cbzxy"));  // -1
        
        
    }
}