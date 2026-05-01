package devlibs.java;

public class JavaHelper {
    public static void printArray(int[] nums) {
        int n = nums.length;

        System.out.print("{");

        for (int i = 0; i < n; i++) {
            System.out.print(nums[i]);

            if (n != n-1) System.out.print(", ");
        }

        System.out.println("}");
    }
    
}
