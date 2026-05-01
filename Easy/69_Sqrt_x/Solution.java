


class Solution {
    public int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        int left = 1;
        int right = x / 2;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (mid <= x / mid) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
    
        // test cases 1
        System.out.println(solution.mySqrt(4));// Output: 2

        // test cases 2
        System.out.println(solution.mySqrt(8));// Output: 2
    }
}