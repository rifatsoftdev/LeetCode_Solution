#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller;
        vector<int> equal;
        vector<int> greater;

        for (int num : nums) {
            if (num < pivot) {
                smaller.push_back(num);
            } else if (num == pivot) {
                equal.push_back(num);
            } else {
                greater.push_back(num);
            }
        }

        vector<int> result;

        result.insert(result.end(), smaller.begin(), smaller.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), greater.begin(), greater.end());

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {9,12,5,10,14,3,10};
    vector<int> result1 = solution.pivotArray(nums1, 10);
    printVec(result1);  // [9,5,3,10,10,12,14]

    // test cases 2
    vector<int> nums2 = {-3,4,3,2};
    vector<int> result2 = solution.pivotArray(nums2, 2);
    printVec(result2);  // [-3,2,4,3]

    return 0;
}