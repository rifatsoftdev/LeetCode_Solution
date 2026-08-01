

class Solution {
    public int maxProfit(int[] prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }
        
        return maxProfit;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] prices1 = {7,1,5,3,6,4};
        System.out.println(solution.maxProfit(prices1));

        // test cases 2
        int[] prices2 = {7,6,4,3,1};
        System.out.println(solution.maxProfit(prices2));
    }
}