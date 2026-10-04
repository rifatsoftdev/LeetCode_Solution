import java.util.*;


public class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length())
            return false;

        char[] chars = s1.toCharArray();
        Arrays.sort(chars);
        String sortedS1 = new String(chars);

        int n = s1.length();

        for (int i = n; i <= s2.length(); i++) {
            String s = s2.substring(i - n, i);

            char[] window = s.toCharArray();
            Arrays.sort(window);

            if (sortedS1.equals(new String(window)))
                return true;
        }

        return false;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String s11 = "ab";
        String s21 = "eidbaooo";
        System.out.println(solution.checkInclusion(s11, s21));

        // test cases 2
        String s12 = "ab";
        String s22 = "eidboaoo";
        System.out.println(solution.checkInclusion(s12, s22));
        
        
    }
}