

public class Solution {
    public int getLucky(String s, int k) {
        StringBuilder sb = new StringBuilder();

        for (char c : s.toCharArray()) {
            sb.append(c - 'a' + 1);
        }

        String str = sb.toString();

        for (int i = 0; i < k; i++) {
            int sum = 0;
            
            for (char c : str.toCharArray()) {
                sum += c - '0';
            }
            str = String.valueOf(sum);
        }

        return Integer.parseInt(str);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.getLucky("iiii", 1));

        // test cases 2
        System.out.println(solution.getLucky("leetcode", 2));

        // test cases 3
        System.out.println(solution.getLucky("zbax", 2));
    }
}