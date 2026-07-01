

public class Solution {
    public int secondHighest(String s) {

        int fastLarge = -1;
        int secendLarge = -1;

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if (Character.isDigit(ch)) {
                int val = ch - '0';

                if (val > fastLarge) {
                    secendLarge = fastLarge;
                    fastLarge = val;
                } else if (val < fastLarge && val > secendLarge) {
                    secendLarge = val;
                }
            }
        }
        
        return secendLarge;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String s1 = "dfa12321afd";
        System.out.println(solution.secondHighest(s1)); // Output: 2
        
        // test cases 2
        String s2 = "abc1111";
        System.out.println(solution.secondHighest(s2)); // Output: -1
        
    }
}