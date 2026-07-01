


class Solution {
    public int numberOfSteps(int num) {
        int steps = 0;

        while (num > 0) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num -= 1;
            }
            steps++;
        }

        return steps;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.numberOfSteps(14));

        // test cases 2
        System.out.println(solution.numberOfSteps(8));

        // test cases 3
        System.out.println(solution.numberOfSteps(123));
    }
}