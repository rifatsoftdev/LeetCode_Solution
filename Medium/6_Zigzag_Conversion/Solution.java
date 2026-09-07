


public class Solution {
    public String convert(String s, int numRows) {
        if (numRows <= 1) {
            return s;
        }

        StringBuilder[] rows = new StringBuilder[numRows];
        int row = 0;
        int direction = 1;

        for (char c : s.toCharArray()) {
            if (rows[row] == null) {
                rows[row] = new StringBuilder();
            }

            rows[row].append(c);

            if (row == 0) {
                direction = 1;
            } else if (row == numRows - 1) {
                direction = -1;
            }
            
            row += direction;
        }

        StringBuilder result = new StringBuilder();

        for (StringBuilder sb : rows) {
            if (sb != null) {
                result.append(sb);
            }
        }

        return result.toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String s1 = "PAYPALISHIRING";
        int numRows1 = 3;
        System.out.println(solution.convert(s1, numRows1));

        // test cases 2
        String s2 = "PAYPALISHIRING";
        int numRows2 = 4;
        System.out.println(solution.convert(s2, numRows2));

        // test cases 3
        String s3 = "A";
        int numRows3 = 1;
        System.out.println(solution.convert(s3, numRows3));
        
    }
}