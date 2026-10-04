import java.util.*;


public class Solution {
    public int buyChoco(int[] prices, int money) {
        int firstMin = 100;
        int secondMin = 100;

        for (int price : prices) {
            if (price < firstMin) {
                secondMin = firstMin;
                firstMin = price;
            }
            else if (price < secondMin) {
                secondMin = price;
            }
        }

        int cost = firstMin + secondMin;

        if (cost <= money) {
            return money - cost;
        }

        return money;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] prices1 = {1,2,2};
        int money1 = 3;
        System.out.println(solution.buyChoco(prices1, money1));

        // test cases 2
        int[] prices2 = {3,2,3};
        int money2 = 3;
        System.out.println(solution.buyChoco(prices2, money2));
        
        
    }
}