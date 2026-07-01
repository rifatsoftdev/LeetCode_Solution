import java.util.Arrays;


public class Solution {
    public int findContentChildren(int[] g, int[] s) {
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
        int[] g1 = {1, 2, 3};
        int[] s1 = {1, 1};
        System.out.println(solution.findContentChildren(g1, s1)); // Expected output: 1
        
        // test cases 2
        int[] g2 = {1, 2};
        int[] s2 = {1, 2, 3};
        System.out.println(solution.findContentChildren(g2, s2)); // Expected output: 2
        
    }
}