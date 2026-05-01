#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Minimum distance between three equal elements:
    1. We can use a hash map to store the indices of each number in the array.
    2. For each number that appears at least three times, we can calculate the distance between the first and third occurrence.
    3. The distance can be calculated as `2 * (c - a)`, where `a` is the index of the first occurrence and `c` is the index of the third occurrence. This is because the second occurrence will be between the first and third, so the total distance will be twice the distance from the first to the third occurrence.
    4. We keep track of the minimum distance found and return it at the end. If no such triplet exists, we return -1.

Time Complexity: O(n), where n is the length of the input array. We traverse the array once to build the hash map and then iterate through the map to find the minimum distance.
Space Complexity: O(n) in the worst case, if all elements in the array are unique, we will store all indices in the hash map.
*/

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        if (n < 3) {
            return -1;
        }

        unordered_map<int, vector<int>> m;

        for (int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto &it : m) {
            vector<int> &indices = it.second;

            if (indices.size() < 3) continue;

            for (int i = 0; i + 2 < indices.size(); i++) {
                int a = indices[i];
                int b = indices[i + 1];
                int c = indices[i + 2];

                int dist = 2 * (c - a); // key simplification

                ans = min(ans, dist);
            }
        }

        if (ans == INT_MAX) return -1;
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {1,2,1,1,3};
    cout << solution.minimumDistance(nums1) << endl; // Output: 6

    vector<int> nums2 = {1,1,2,3,2,1,2};
    cout << solution.minimumDistance(nums2) << endl; // Output: 8

    vector<int> nums3 = {1};
    cout << solution.minimumDistance(nums3) << endl; // Output: -1

    return 0;
}