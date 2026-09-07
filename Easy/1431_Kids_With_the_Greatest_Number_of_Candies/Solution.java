import java.util.*;


public class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int maxC = Arrays.stream(candies).max().getAsInt();
        List<Boolean> result = new ArrayList<>();

        for (int c : candies) {
            result.add(c + extraCandies >= maxC);
        }

        return result;
    }

    private static void printVec(List<Boolean> vec) {
        System.out.print("[");
        for (int i = 0; i < vec.size(); i++) {
            System.out.print(vec.get(i));
            if (i != vec.size() - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] candies1 = {2,3,5,1,3};
        int extraCandies1 = 3;
        List<Boolean> result1 = solution.kidsWithCandies(candies1, extraCandies1);
        printVec(result1);

        // test cases 2
        int[] candies2 = {4,2,1,1,2};
        int extraCandies2 = 1;
        List<Boolean> result2 = solution.kidsWithCandies(candies2, extraCandies2);
        printVec(result2);

        // test cases 3
        int[] candies3 = {12,1,12};
        int extraCandies3 = 10;
        List<Boolean> result3 = solution.kidsWithCandies(candies3, extraCandies3);
        printVec(result3);
        
    }
}