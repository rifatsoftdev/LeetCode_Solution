


class Solution {
    public Boolean canConstruct(String ransomNote, String magazine) {
        int[] freq = new int[26];

        for (char c : magazine.toCharArray()) {
            freq[c - 'a']++;
        }

        for (char c : ransomNote.toCharArray()) {
            freq[c - 'a']--;

            if (freq[c - 'a'] < 0)
                return false;
        }

        return true;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        
        // test cases 1
        String ransomNote1 = "a";
        String magazine1 = "b";
        System.out.println(sol.canConstruct(ransomNote1, magazine1));

        // test cases 2
        String ransomNote2 = "aa";
        String magazine2 = "ab";
        System.out.println(sol.canConstruct(ransomNote2, magazine2));

        // test cases 3
        String ransomNote3 = "aa";
        String magazine3 = "aab";
        System.out.println(sol.canConstruct(ransomNote3, magazine3));
    }
}