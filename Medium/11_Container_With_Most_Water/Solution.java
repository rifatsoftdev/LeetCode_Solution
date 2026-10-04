import java.util.*;


public class Solution {
    public int maxArea(int[] height) {
        int result = 0;
        int left = 0;
        int right = height.length - 1;

        while (left < right) {
            int w = right - left;
            int h = Math.min(height[left], height[right]);
            int a = w * h;
            result = Math.max(a, result);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] height1 = {1,8,6,2,5,4,8,3,7};
        System.out.println(solution.maxArea(height1));

        // test cases 2
        int[] height2 = {1,1};
        System.out.println(solution.maxArea(height2));
        
    }
}