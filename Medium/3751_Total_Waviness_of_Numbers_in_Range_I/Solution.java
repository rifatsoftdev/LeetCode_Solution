

public class Solution {
    private int waviness(int x) {
        char[] s = String.valueOf(x).toCharArray();

        if (s.length < 3) return 0;

        int cnt = 0;

        for (int i = 1; i < s.length - 1; i++) {
            if ((s[i] > s[i-1] && s[i] > s[i+1]) ||
                (s[i] < s[i-1] && s[i] < s[i+1])) {
                cnt++;
            }
        }

        return cnt;
    }

    public int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int x = num1; x <= num2; x++) {
            ans += waviness(x);
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.totalWaviness(120, 130));

        // test cases 2
        System.out.println(solution.totalWaviness(198, 202));

        // test cases 3
        System.out.println(solution.totalWaviness(4848, 4848));
        
    }
}