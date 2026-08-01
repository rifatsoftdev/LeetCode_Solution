


public class Solution {
    public int strStr(String haystack, String needle) {
        int index = -1;
        int haystackLength = haystack.length();
        int needleLength = needle.length();

        char[] haystackArr = haystack.toCharArray();
        char[] needleArr = needle.toCharArray();

        if (needleLength == 0) {
            return 0;
        }
        if (haystackLength < needleLength) {
            return -1;
        }

        for (int i = 0; i <= haystackLength - needleLength; i++) {
            int j;

            for (j = 0; j < needleLength; j++) {
                if (haystackArr[i + j] != needleArr[j]) {
                    break;
                }
            }

            if (j == needleLength) {
                index = i;
                break;
            }
        }
        
        return index;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String haystack1 = "sadbutsad";
        String needle1 = "sad";
        System.out.println(solution.strStr(haystack1, needle1)); // Output:

        // test cases 2
        String haystack2 = "leetcode";
        String needle2 = "leeto";
        System.out.println(solution.strStr(haystack2, needle2)); // Output: -1
        
    }
}