

public class Solution {
    public boolean noZero(int x) {
        while (x > 0) {
            if (x % 10 == 0)
                return false;
            x /= 10;
        }
        return true;
    }

    public int[] getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;

            if (noZero(a) && noZero(b))
                return new int[]{a, b};
        }

        return new int[]{};
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] result1 = solution.getNoZeroIntegers(2);
        System.out.println("[" + result1[0] + ", " + result1[1] + "]");
        
        // test cases 2
        int[] result2 = solution.getNoZeroIntegers(11);
        System.out.println("[" + result2[0] + ", " + result2[1] + "]");
        
    }
}