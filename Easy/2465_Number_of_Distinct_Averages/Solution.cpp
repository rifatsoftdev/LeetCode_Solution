#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;
        set<double> data;

        while (left < right) {
            double ave = (nums[left] + nums[right]) / 2.0;
            data.insert(ave);
            left++;
            right--;
        }

        return data.size();
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {4, 1, 4, 0, 3, 5};
    cout << solution.distinctAverages(nums1) << endl;
    
    // test cases 2
    vector<int> nums2 = {1, 100};
    cout << solution.distinctAverages(nums2) << endl;

    return 0;
}