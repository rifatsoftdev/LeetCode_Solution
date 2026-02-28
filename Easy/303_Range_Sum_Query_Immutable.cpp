#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Brute Force Approach (Linear Search):
1. Iterate through the array and count the occurrences of each element.
2. Return the element that occurs only once.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class NumArray {
public:
    vector<int> prefixSum;

    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        int sum = prefixSum[right + 1] - prefixSum[left];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
*/


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> num = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(num);
    cout << obj->sumRange(0, 2) << endl; // Output: 1
    cout << obj->sumRange(2, 5) << endl; // Output: -1
    cout << obj->sumRange(0, 5) << endl; // Output: -3
    
    return 0;
}