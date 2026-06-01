

public class Solution {
    private int sumOfDrgit(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    public int countEven(int num) {
        int ans = 0;

        for (int i = 2; i <= num; i++) {
            int n = sumOfDrgit(i);
            if (n % 2 == 0) ans++;
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.countEven(4));

        // test cases 2
        System.out.println(solution.countEven(30));
    }
}