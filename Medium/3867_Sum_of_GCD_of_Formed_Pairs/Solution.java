import java.util.ArrayList;
import java.util.Collections;


public class Solution {
    public int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    public long gcdSum(int[] nums) {
        ArrayList<Integer> prefix = new ArrayList<>();

        int mx = 0;

        for (int x : nums) {
            mx = Math.max(mx, x);
            prefix.add(gcd(x, mx));
        }

        Collections.sort(prefix);

        long ans = 0;

        int l = 0;
        int r = prefix.size() - 1;

        while (l < r) {
            ans += gcd(prefix.get(l), prefix.get(r));
            l++;
            r--;
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {2,6,4};
        System.out.println(solution.gcdSum(nums1));
        
        // test cases 2
        int[] nums2 = {3,6,2,8};
        System.out.println(solution.gcdSum(nums2));
    }
}