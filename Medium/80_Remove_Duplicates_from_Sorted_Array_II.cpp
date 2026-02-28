#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Hash Map: O(n)
1. Create a hash map to count the occurrences of each element in the array.
2. Iterate through the array and for each element, check if it has been seen less than 2 times.
3. If it has been seen less than 2 times, add it to the hash map and update the position in the array where it should be placed.
4. Return the new length of the array after removing duplicates.

Time Complexity: O(n) because we traverse the array once to count occurrences and once to update the array.
Space Complexity: O(n) in the worst case if all elements are unique, as we need to store the count of each element in the hash map. However, since the problem states that the array is sorted, the space complexity can be considered O(1) because we only need to keep track of the last two occurrences of each element.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mp;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (mp[nums[i]] < 2) {
                mp[nums[i]]++;
                nums[ans++] = nums[i];
            }
        }
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {1,1,1,2,2,3};
    cout << solution.removeDuplicates(nums1) << endl; // Output: 5

    vector<int> nums2 = {0,0,1,1,1,1,2,3,3};
    cout << solution.removeDuplicates(nums2) << endl; // Output: 7

    return 0;
}