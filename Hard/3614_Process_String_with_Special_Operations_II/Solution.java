


public class Solution {
    public char processStr(String s, long k) {
        long m = 0;

        // Final length
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if (c == '*') {
                if (m > 0) m--;
            } else if (c == '#') {
                m *= 2;
            } else if (c != '%') {
                m++;
            }
        }

        if (k >= m) return '.';

        // Reverse simulation
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);

            if (c == '*') {
                m++;
            }
            else if (c == '#') {
                m /= 2;
                if (k >= m) k -= m;
            }
            else if (c == '%') {
                k = m - 1 - k;
            }
            else { // letter
                m--;
                if (k == m) return c;
            }
        }

        return '.';
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.processStr("a#b%*", 1)); // Expected: 'a'
        
        // test cases 2
        System.out.println(solution.processStr("cd%#*#", 3)); // Expected: 'd'

        // test cases 3
        System.out.println(solution.processStr("z*#", 4)); // Expected: '.'
        
        
    }
}