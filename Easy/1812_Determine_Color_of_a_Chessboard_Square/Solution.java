

public class Solution {
    public boolean squareIsWhite(String coordinates) {
        int col = coordinates.charAt(0) - 'a' + 1;
        int row = coordinates.charAt(1) - '0';

        return (row + col) % 2 == 0;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String coordinates1 = "a1";
        System.out.println(solution.squareIsWhite(coordinates1));
        
        // test cases 2
        String coordinates2 = "h3";
        System.out.println(solution.squareIsWhite(coordinates2));

        // test cases 3
        String coordinates3 = "c7";
        System.out.println(solution.squareIsWhite(coordinates3));
        
    }
}