

public class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int zero = 0;
        int one = 0;

        for (int student : students) {
            if (student == 0)
                zero++;
            else
                one++;
        }

        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (zero == 0)
                    return one;
                zero--;
            } else {
                if (one == 0)
                    return zero;
                one--;
            }
        }

        return 0;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] students1 = {1, 1, 0, 0};
        int[] sandwiches1 = {0, 1, 0, 1};
        System.out.println(solution.countStudents(students1, sandwiches1)); // Output: 0
        
        // test cases 2
        int[] students2 = {1, 1, 1, 0, 0, 1};
        int[] sandwiches2 = {1, 0, 0, 0, 1, 1};
        System.out.println(solution.countStudents(students2, sandwiches2)); // Output: 3
        
    }
}