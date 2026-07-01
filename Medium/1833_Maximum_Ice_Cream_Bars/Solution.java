import java.util.Arrays;


public class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);

        int count = 0;

        for (int cost : costs) {
            if (coins < cost) break;

            coins -= cost;
            count++;
        }

        return count;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] costs1 = {1,3,2,4,1};
        int coins1 = 7;
        System.out.println(solution.maxIceCream(costs1, coins1));

        // test cases 2
        int[] costs2 = {10,6,8,7,7,8};
        int coins2 = 5;
        System.out.println(solution.maxIceCream(costs2, coins2));

        // test cases 3
        int[] costs3 = {1,6,3,1,2,5};
        int coins3 = 20;
        System.out.println(solution.maxIceCream(costs3, coins3));
    }
}