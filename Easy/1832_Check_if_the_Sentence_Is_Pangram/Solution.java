

public class Solution {
    public boolean checkIfPangram(String sentence) {
        if (sentence.length() < 26) {
            return false;
        }

        int seen = 0;
        for (int i = 0; i < sentence.length(); i++) {
            seen |= (1 << (sentence.charAt(i) - 'a'));
        }

        return seen == (1 << 26) - 1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.checkIfPangram("thequickbrownfoxjumpsoverthelazydog"));

        // test cases 2
        System.out.println(solution.checkIfPangram("leetcode"));
        
    }
}