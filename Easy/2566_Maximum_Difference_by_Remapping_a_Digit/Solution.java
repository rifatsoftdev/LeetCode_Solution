


class Solution {
    public int minMaxDifference(int num) {
        String s = Integer.toString(num);
        String maxNum = "";
        String minNum = "";
        char fastNum = '0';
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) != '9') {
                fastNum = s.charAt(i);
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == fastNum) {
                maxNum += '9';
            } else {
                maxNum += s.charAt(i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) != '0') {
                fastNum = s.charAt(i);
                break;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == fastNum) {
                minNum += '0';
            } else {
                minNum += s.charAt(i);
            }
        }

        return Integer.parseInt(maxNum) - Integer.parseInt(minNum);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        System.out.println(solution.minMaxDifference(11891)); // Output: 99009

        // test cases 2
        System.out.println(solution.minMaxDifference(90)); // Output: 99
    }
}