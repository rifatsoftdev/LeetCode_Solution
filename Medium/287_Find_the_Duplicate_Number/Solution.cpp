#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Find the Duplicate Number (Sorting):
    1. Sort the input array `nums` in ascending order.
    2. Iterate through the sorted array and compare each element with the next one.
    3. If two adjacent elements are equal, that element is the duplicate.
    4. Return the duplicate element.

Time Complexity: O(n log n) due to sorting.
Space Complexity: O(1) or O(n) depending on the sorting algorithm's space requirements.

Note: This problem can be solved in O(n) time and O(1) space using Floyd's Tortoise and Hare (Cycle Detection) algorithm without modifying the array.
*/

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         for (int i = 0; i < nums.size()-1; i++) {
//             if (nums[i] == nums[i+1]) return nums[i];
//         }

//         return -1;
//     }
// };




/* ================================================================================
Solution 2:

Find the Duplicate Number (Floyd's Tortoise and Hare / Cycle Detection):
    1. Treat the array as a linked list where `nums[i]` points to the index `nums[i]`.
    2. Since there is a duplicate, a cycle must exist in this "linked list".
    3. Use two pointers, `slow` and `fast`. Move `slow` by one step and `fast` by two steps until they meet inside the cycle.
    4. Reset `slow` to the start of the array and move both `slow` and `fast` by one step at a time.
    5. The point where they meet again is the entrance to the cycle, which corresponds to the duplicate number.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {1,3,4,2,2};
    cout << solution.findDuplicate(nums1) << endl;

    vector<int> nums2 = {3,1,3,4,2};
    cout << solution.findDuplicate(nums2) << endl;

    vector<int> nums3 = {3,3,3,3,3};
    cout << solution.findDuplicate(nums3) << endl;

    return 0;
}