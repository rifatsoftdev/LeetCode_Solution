


public class Solution {
    public double angleClock(int hour, int minutes) {
        double minutesAng = minutes * 6.0;
        double hourAng = (hour * 30.0) + (minutes * 0.5);
        double diff = Math.abs(minutesAng - hourAng);
        return Math.min(diff, 360.0 - diff);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.angleClock(12, 30)); // Expected: 165.0
        
        // test cases 2
        System.out.println(solution.angleClock(3, 30)); // Expected: 75.0

        // test cases 3
        System.out.println(solution.angleClock(3, 15)); // Expected: 7.5
        
    }
}