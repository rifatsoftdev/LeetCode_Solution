import java.util.ArrayList;
import java.util.List;

public class Solution {
    public int[] sumZero(int n) {
        List<Integer> result = new ArrayList<>();

        if (n % 2 == 1) {
            result.add(0);
        }

        for (int i = 1; i <= n / 2; i++) {
            result.add(i);
            result.add(-i);
        }

        // Convert List to array
        int[] arr = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            arr[i] = result.get(i);
        }

        return arr;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int n1 = 5;
        int[] result1 = solution.sumZero(n1);
        System.out.println(result1); // Output: [-2, -1, 0, 1, 2]

        // test cases 2
        int n2 = 3;
        int[] result2 = solution.sumZero(n2);
        System.out.println(result2); // Output: [-1, 0, 1]

        // test cases 3
        int n3 = 1;
        int[] result3 = solution.sumZero(n3);
        System.out.println(result3); // Output: [0]

    }
}