#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> counts;
        for (int x : nums) {
            counts[x]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (counts[a] != counts[b]) {
                return counts[a] < counts[b];
            }
            return a > b;
        });

        return nums;
        
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1,1,2,2,2,3};
    vector<int> result1 = solution.frequencySort(nums1);
    printVec(result1);

    // test cases 2
    vector<int> nums2 = {2,3,1,3,2};
    vector<int> result2 = solution.frequencySort(nums2);
    printVec(result2);

    // test cases 2
    vector<int> nums3 = {-1,1,-6,4,5,-6,1,4,1};
    vector<int> result3 = solution.frequencySort(nums3);
    printVec(result3);

    return 0;
}