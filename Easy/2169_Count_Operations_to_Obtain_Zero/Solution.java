

public class Solution {
    public int countOperations(int num1, int num2) {
        int stap = 0;

        while (num1 != 0 && num2 != 0) {
            if (num1 >= num2) {
                num1 -= num2;
            } else {
                num2 -= num1;
            }

            stap++;
        }

        return stap;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.countOperations(2, 3));

        // test cases 2
        System.out.println(solution.countOperations(10, 10));
        
    }
}