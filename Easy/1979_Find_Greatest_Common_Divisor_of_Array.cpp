#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Brute Force Approach (Sorting and GCD Calculation):
1. Sort the array to find the minimum and maximum elements.
2. Calculate the greatest common divisor (GCD) of the minimum and maximum elements using the Euclidean algorithm.

Time Complexity: O(n log n) (due to sorting)
Space Complexity: O(1) (ignoring the space used for sorting)
*/

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }

    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return gcd(nums[0], nums[nums.size()-1]);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {2,5,6,9,10};
    cout << solution.findGCD(nums1) << endl;

    vector<int> nums2 = {7,5,6,8,3};
    cout << solution.findGCD(nums2) << endl;

    vector<int> nums3 = {3,3};
    cout << solution.findGCD(nums3) << endl;

    return 0;
}