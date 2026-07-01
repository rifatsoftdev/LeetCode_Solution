

public class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] freq = new int[26];

        for (char ch : chars.toCharArray()) {
            freq[ch - 'a']++;
        }

        int ans = 0;

        for (String word : words) {
            boolean good = true;
            int[] temp = freq.clone();

            for (char ch : word.toCharArray()) {
            
                if (--temp[ch - 'a'] < 0) {
                    good = false;
                    break;
                }
            }

            if (good) ans += word.length();
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String[] words1 = {"cat", "bt", "hat", "tree"};
        String chars1 = "atach";
        System.out.println(solution.countCharacters(words1, chars1)); // Output: 6

        // test cases 2
        String[] words2 = {"hello", "world", "leetcode"};
        String chars2 = "welldonehoneyr";
        System.out.println(solution.countCharacters(words2, chars2)); // Output: 10
        
    }
}