


public class Solution {
    private boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }

    public boolean completePrime(int num) {
        String s = String.valueOf(num);

        // prefix
        for (int i = 1; i <= s.length(); i++) {
            if (!isPrime(Integer.parseInt(s.substring(0, i)))) {
                return false;
            }
        }

        // suffix
        for (int i = 0; i < s.length(); i++) {
            if (!isPrime(Integer.parseInt(s.substring(i)))) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int num1 = 23;
        System.out.println(solution.completePrime(num1));
        
        // test cases 2
        int num2 = 39;
        System.out.println(solution.completePrime(num2));

        // test cases 3
        int num3 = 7;
        System.out.println(solution.completePrime(num3));
        
        
    }
}