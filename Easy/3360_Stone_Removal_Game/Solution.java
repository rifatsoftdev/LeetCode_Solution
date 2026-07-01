


public class Solution {
    public boolean canAliceWin(int n) {
        boolean Alice = true;
        int turn = 10;

        while (n >= turn) {
            n -= turn;
            turn--;
            Alice = !Alice;
        }

        return !Alice;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int n1 = 12;
        System.out.println(solution.canAliceWin(n1));
        
        // test cases 2
        int n2 = 1;
        System.out.println(solution.canAliceWin(n2));
        
    }
}