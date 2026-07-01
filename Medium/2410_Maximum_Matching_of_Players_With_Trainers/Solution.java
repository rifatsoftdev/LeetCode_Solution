import java.util.Arrays;


public class Solution {
    public int matchPlayersAndTrainers(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);

        int child = 0;
        int cookie = 0;

        while (child < g.length && cookie < s.length) {

            if (s[cookie] >= g[child]) {
                child++;
            }

            cookie++;
        }

        return child;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] players1 = {4, 7, 9};
        int[] trainers1 = {8, 2, 5, 8};
        System.out.println(solution.matchPlayersAndTrainers(players1, trainers1)); // Output: 2
        
        // test cases 2
        int[] players2 = {1, 1, 1};
        int[] trainers2 = {10};
        System.out.println(solution.matchPlayersAndTrainers(players2, trainers2)); // Output: 1
        
    }
}