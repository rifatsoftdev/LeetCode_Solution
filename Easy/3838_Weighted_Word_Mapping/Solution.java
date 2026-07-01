


public class Solution {
    public String mapWordWeights(String[] words, int[] weights) {
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            int sum = 0;

            for (int j = 0; j < word.length(); j++) {
                char ch = word.charAt(j);
                sum += weights[ch - 'a'];
            }

            char mappedChar = (char) ('z' - (sum % 26));
            result.append(mappedChar);
        }

        return result.toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String[] words1 = {"abcd","def","xyz"};
        int[] weights1 = {5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2};
        System.out.println(solution.mapWordWeights(words1, weights1)); // Expected output: "rij"
        
        // test cases 2
        String[] words2 = {"a","b","c"};
        int[] weights2 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        System.out.println(solution.mapWordWeights(words2, weights2)); // Expected output: "yyy"
        
        // test cases 3
        String[] words3 = {"abcd"};
        int[] weights3 = {7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5};
        System.out.println(solution.mapWordWeights(words3, weights3)); // Expected output: "g"
        
    }
}