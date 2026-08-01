import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Integer> mp = new HashMap<>();

        for (int i = 0; i < list1.length; i++) {
            mp.put(list1[i], i);
        }

        int mn = Integer.MAX_VALUE;
        List<String> ans = new ArrayList<>();

        for (int i = 0; i < list2.length; i++) {
            if (mp.containsKey(list2[i])) {
                int sum = mp.get(list2[i]) + i;

                if (sum < mn) {
                    mn = sum;
                    ans.clear();
                    ans.add(list2[i]);
                }
                else if (sum == mn) {
                    ans.add(list2[i]);
                }
            }
        }

        return ans.toArray(new String[0]);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        String[] list11 = {"Shogun","Tapioca Express","Burger King","KFC"};
        String[] list12 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};
        String[] ans1 = solution.findRestaurant(list11, list12);
        System.out.println(ans1.toString());

        // test cases 2
        String[] list21 = {"Shogun","Tapioca Express","Burger King","KFC"};
        String[] list22 = {"KFC","Shogun","Burger King"};
        String[] ans2 = solution.findRestaurant(list21, list22);
        System.out.println(ans2.toString());

        // test cases 3
        String[] list31 = {"happy","sad","good"};
        String[] list32 = {"sad","happy","good"};
        String[] ans3 = solution.findRestaurant(list31, list32);
        System.out.println(ans3.toString());
        
    }
}