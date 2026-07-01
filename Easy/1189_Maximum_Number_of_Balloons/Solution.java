


class Solution {
    public int maxNumberOfBalloons(String text) {
        int[] freq = new int[26];

        for (char c : text.toCharArray()) {
            freq[c - 'a']++;
        }

        return Math.min(
            Math.min(freq['b' - 'a'], freq['a' - 'a']),
            Math.min(
                freq['l' - 'a'] / 2,
                Math.min(freq['o' - 'a'] / 2, freq['n' - 'a'])
            )
        );
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String text1 = "nlaebolko";
        System.out.println(solution.maxNumberOfBalloons(text1));

        // test cases 2
        String text2 = "loonbalxballpoon";
        System.out.println(solution.maxNumberOfBalloons(text2));

        // test cases 3
        String text3 = "leetcode";
        System.out.println(solution.maxNumberOfBalloons(text3));
        
    }
}