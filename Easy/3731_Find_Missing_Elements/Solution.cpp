#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> missing;
        unordered_map<int, int> countMap;
        int minNum = INT_MAX;
        int maxNum = INT_MIN;

        for (int num : nums) {
            countMap[num]++;
            minNum = min(minNum, num);
            maxNum = max(maxNum, num);
        }

        for (int i = minNum; i <= maxNum; i++) {
            if (countMap.find(i) == countMap.end()) {
                missing.push_back(i);
            }
        }

        return missing;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1,4,2,5};
    vector<int> missing1 = solution.findMissingElements(nums1);
    printVec(missing1); // Expected output: [3]

    // test cases 2
    vector<int> nums2 = {7,8,6,9};
    vector<int> missing2 = solution.findMissingElements(nums2);
    printVec(missing2); // Expected output: []

    // test cases 3
    vector<int> nums3 = {5,1};
    vector<int> missing3 = solution.findMissingElements(nums3);
    printVec(missing3); // Expected output: [2,3,4]    

    return 0;
}