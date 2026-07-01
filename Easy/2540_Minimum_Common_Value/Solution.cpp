#include <iostream>
#include <vector>
#include <algorithm>
#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.




class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            }
            if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return -1;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums11 = {1,2,3}, nums12 = {2,4};
    cout << solution.getCommon(nums11, nums12) << endl;

    vector<int> nums21 = {1,2,3,6}, nums22 = {2,3,4,5};
    cout << solution.getCommon(nums21, nums22) << endl;

    return 0;
}