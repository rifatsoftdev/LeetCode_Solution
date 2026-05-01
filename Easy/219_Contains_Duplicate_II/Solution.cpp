#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Contains Duplicate II:
    1. Use a hash map to store the last index of each number.
    2. Iterate through the array, and for each number, check if it has been seen before and if the distance between the current index and the last index is less than or equal to k.
    3. If such a condition is met, return true. Otherwise, update the last index of the number in the hash map.
    4. If the loop ends without finding any duplicates within the specified distance, return false.

Time Complexity: O(n), where n is the number of elements in the array.
Space Complexity: O(n) in the worst case, if all elements are unique and stored in the hash map.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex; // number -> last index

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (lastIndex.count(num) && i - lastIndex[num] <= k) {
                return true;
            }
            lastIndex[num] = i;
        }

        return false;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {1, 2, 3, 1};
    int k1 = 3;
    cout << solution.containsNearbyDuplicate(nums1, k1) << endl; // Output: true

    vector<int> nums2 = {1, 0, 1, 1};
    int k2 = 1;
    cout << solution.containsNearbyDuplicate(nums2, k2) << endl; // Output: true

    vector<int> nums3 = {1, 2, 3, 1, 2, 3};
    int k3 = 2;
    cout << solution.containsNearbyDuplicate(nums3, k3) << endl; // Output: false

    return 0;
}