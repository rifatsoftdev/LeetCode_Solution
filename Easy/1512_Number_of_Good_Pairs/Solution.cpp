#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> countMap;
        int goodPairs = 0;

        for (int num : nums) {
            goodPairs += countMap[num];
            countMap[num]++;
        }

        return goodPairs; 
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1, 2, 3, 1, 1, 3};
    int result1 = solution.numIdenticalPairs(nums1);
    cout << result1 << endl;

    // test cases 2
    vector<int> nums2 = {1, 1, 1, 1};
    int result2 = solution.numIdenticalPairs(nums2);
    cout << result2 << endl;

    // test cases 3
    vector<int> nums3 = {1, 2, 3};
    int result3 = solution.numIdenticalPairs(nums3);
    cout << result3 << endl;

    return 0;
}