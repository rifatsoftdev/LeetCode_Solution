import java.util.*;


public class Solution {
    public double[] convertTemperature(double celsius) {
        double kelvin = celsius + 273.15;
        double fahrenheit = celsius * 1.80 + 32.00;

        return new double[] {kelvin, fahrenheit};
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        double celsius1 = 36.50;
        double[] result1 = solution.convertTemperature(celsius1);
        System.out.println(result1[0] + " " + result1[1]);

        // test cases 2
        double celsius2 = 122.11;
        double[] result2 = solution.convertTemperature(celsius2);
        System.out.println(result2[0] + " " + result2[1]);
        
    }
}