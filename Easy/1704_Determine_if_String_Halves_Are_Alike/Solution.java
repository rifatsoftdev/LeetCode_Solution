

public class Solution {
    private boolean isVowel(char c) {
        return "aeiouAEIOU".indexOf(c) != -1;
    }

    public boolean halvesAreAlike(String s) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n / 2; i++) {
            if (isVowel(s.charAt(i))) {
                count++;
            }
        }
        for (int i = n / 2; i < n; i++) {
            if (isVowel(s.charAt(i))) {
                count--;
            }
        }

        return count == 0;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.halvesAreAlike("book")); // true

        // test cases 2
        System.out.println(solution.halvesAreAlike("textbook")); // false
        
    }
}