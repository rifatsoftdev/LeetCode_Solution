#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Optimal Approach (Two Pointers):
1. Use two pointers to iterate through both sorted arrays simultaneously.
2. If the elements at both pointers are equal, return that element as the minimum common value.
3. If the element in the first array is smaller, move the pointer of the first array forward; otherwise, move the pointer of the second array forward.
4. If no common value is found by the end of the iteration, return -1.

Time Complexity: O(n + m) (where n and m are the lengths of the two arrays)
Space Complexity: O(1)
*/

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