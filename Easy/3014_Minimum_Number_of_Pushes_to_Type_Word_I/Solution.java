


public class Solution {
    public int minimumPushes(String word) {
        int ans = 0;

        for (int i = 0; i < word.length(); i++) {
            ans += i / 8 + 1;
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String word1 = "abcde";
        System.out.println(solution.minimumPushes(word1));

        // test cases 2
        String word2 = "xycdefghij";
        System.out.println(solution.minimumPushes(word2));
        
    }
}