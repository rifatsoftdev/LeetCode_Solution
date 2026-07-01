


public class Solution {
    public String convertDateToBinary(String date) {
        String[] parts = date.split("-"); // YYYY, MM, DD

        String year = Integer.toBinaryString(Integer.parseInt(parts[0]));
        String month = Integer.toBinaryString(Integer.parseInt(parts[1]));
        String day = Integer.toBinaryString(Integer.parseInt(parts[2]));

        return year + "-" + month + "-" + day;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String date1 = "2080-02-29";
        System.out.println(solution.convertDateToBinary(date1));
        
        // test cases 2
        String date2 = "1900-01-01";
        System.out.println(solution.convertDateToBinary(date2));
        
    }
}