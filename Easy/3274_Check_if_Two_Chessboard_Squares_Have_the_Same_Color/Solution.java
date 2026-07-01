

public class Solution {
    public boolean squareIsWhite(String coordinates) {
        int col = coordinates.charAt(0) - 'a' + 1;
        int row = coordinates.charAt(1) - '0';

        return (row + col) % 2 == 0;
    }

    public boolean checkTwoChessboards(String coordinate1, String coordinate2) {
        return squareIsWhite(coordinate1) == squareIsWhite(coordinate2);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String coordinate1_1 = "a1";
        String coordinate1_2 = "c3";
        System.out.println(solution.checkTwoChessboards(coordinate1_1, coordinate1_2));
        
        // test cases 2
        String coordinate2_1 = "a1";
        String coordinate2_2 = "h3";
        System.out.println(solution.checkTwoChessboards(coordinate2_1, coordinate2_2));
        
    }
}