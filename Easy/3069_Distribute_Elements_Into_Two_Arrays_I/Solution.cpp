#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        int arr1Last = nums[0];
        int arr2Last = nums[1];

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            if (arr1Last > arr2Last) {
                arr1.push_back(nums[i]);
                arr1Last = nums[i];
            } else {
                arr2.push_back(nums[i]);
                arr2Last = nums[i];
            }
        }

        for (int n: arr2) {
            arr1.push_back(n);
        }

        return arr1;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {2,1,3};
    vector<int> result1 = solution.resultArray(nums1);
    printVec(result1);

    // test cases 2
    vector<int> nums2 = {5,4,3,8};
    vector<int> result2 = solution.resultArray(nums2);
    printVec(result2);

    return 0;
}