

public class Solution {
    public String largestGoodInteger(String num) {
        String ans = "";

        for (int i = 2; i < num.length(); i++) {
            if (num.charAt(i) == num.charAt(i - 1) && num.charAt(i) == num.charAt(i - 2)) {
                String current = num.substring(i - 2, i + 1);

                if (ans.equals("") || current.compareTo(ans) >= 0) {
                    ans = current;
                }
            }
            
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String num1 = "6777133339";
        System.out.println(solution.largestGoodInteger(num1));
        
        // test cases 2
        String num2 = "2300019";
        System.out.println(solution.largestGoodInteger(num2));

        // test cases 3
        String num3 = "42352338";
        System.out.println(solution.largestGoodInteger(num3));
        
    }
}