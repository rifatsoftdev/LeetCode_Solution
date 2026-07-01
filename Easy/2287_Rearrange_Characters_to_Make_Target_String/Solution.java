


public class Solution {
    public int rearrangeCharacters(String s, String target) {
        int[] freqS = new int[26];
        int[] freqT = new int[26];

        for (char c : s.toCharArray()) {
            freqS[c - 'a']++;
        }

        for (char c : target.toCharArray()) {
            freqT[c - 'a']++;
        }

        int minNum = Integer.MAX_VALUE;

        for (int i = 0; i < 26; i++) {
            if (freqT[i] > 0) {
                minNum = Math.min(minNum, freqS[i] / freqT[i]);
            }
        }
        return minNum;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String s1 = "ilovecodingonleetcode", target1 = "code";
        System.out.println(solution.rearrangeCharacters(s1, target1));

        // test cases 2cout << solution.rearrangeCharacters(s2, target2) << endl;
        String s2 = "abcba", target2 = "abc";
        System.out.println(solution.rearrangeCharacters(s2, target2));

        // test cases 3
        String s3 = "abbaccaddaeea", target3 = "aaaaa";
        System.out.println(solution.rearrangeCharacters(s3, target3));
        
        
    }
}