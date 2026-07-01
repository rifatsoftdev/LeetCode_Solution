


public class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        for (int i = 0; i < heights.length; i++) {
            int maxIdx = i;

            for (int j = i; j < heights.length; j++) {
                if (heights[maxIdx] < heights[j]) 
                    maxIdx = j;
            }

            int tempHeight = heights[i];
            heights[i] = heights[maxIdx];
            heights[maxIdx] = tempHeight;

            String tempName = names[i];
            names[i] = names[maxIdx];
            names[maxIdx] = tempName;
            
        }

        return names;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String[] names1 = {"Mary", "John", "Emma"};
        int[] heights1 = {180, 165, 170};
        String[] result1 = solution.sortPeople(names1, heights1);
        for (String name : result1) {
            System.out.print(name + " ");
        }
        System.out.println();
        
        // test cases 2
        String[] names2 = {"Alice", "Bob", "Bob"};
        int[] heights2 = {155, 185, 150};
        String[] result2 = solution.sortPeople(names2, heights2);
        for (String name : result2) {
            System.out.print(name + " ");
        }
        System.out.println();
        
    }
}