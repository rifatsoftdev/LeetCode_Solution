import java.util.*;


public class Solution {
    public int compress(char[] chars) {
        int write = 0;

        for (int read = 0; read < chars.length; read++) {
            int start = read;

            while (read + 1 < chars.length && chars[read] == chars[read + 1]) {
                read++;
            }

            chars[write++] = chars[start];

            if (read > start) {
                String count = Integer.toString(read - start + 1);
                for (char c : count.toCharArray()) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test case 1
        char[] chars1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
        int length1 = solution.compress(chars1);
        System.out.println(length1);

        // test case 2
        char[] chars2 = {'a'};
        int length2 = solution.compress(chars2);
        System.out.println(length2);

        // test case 3
        char[] chars3 = {'a', 'b', 'b', 'b', 'c', 'c', 'c', 'c'};
        int length3 = solution.compress(chars3);
        System.out.println(length3);

    }
}
