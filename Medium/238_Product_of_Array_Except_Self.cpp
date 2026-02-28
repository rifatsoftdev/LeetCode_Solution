#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Brute Force Solution (2 Nested Loops):
1. Use two nested loops to iterate through the array. The outer loop fixes one element and the inner loop calculates the product of all other elements except the fixed one.
2. Store the product in a result array and return it.

Space Complexity: O(n)
Time Complexity: O(n^2)
*/

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans;

//         for (int i = 0; i < n; i++) {
//             int product = 1;
//             for (int j = 0; j < n; j++) {
//                 if (i != j) product *= nums[j];
//             }
//             ans.push_back(product);
//         }
        
//         return ans;
//     }
// };


/*
Optimal Solution (Prefix and Suffix Products):
1. We can calculate the product of all elements to the left of each index and store it in a leftProduct array.
2. We can calculate the product of all elements to the right of each index and store it in a rightProduct array.
3. Finally, we can multiply the corresponding values from leftProduct and rightProduct to get the final answer for each index.

Space Complexity: O(n)
Time Complexity: O(n)
*/

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> leftProduct(n), rightProduct(n), ans(n);

//         leftProduct[0] = 1;
//         for (int i = 1; i < n; i++) {
//             leftProduct[i] = leftProduct[i-1] * nums[i-1];
//         }

//         rightProduct[n-1] = 1;
//         for (int i = n-2; i >= 0; i--) {
//             rightProduct[i] = rightProduct[i+1] * nums[i+1];
//         }

//         for (int i = 0; i < n; i++) {
//             ans[i] = leftProduct[i] * rightProduct[i];
//         }
        
//         return ans;
//     }
// };


/*
Optimal Solution (Prefix and Suffix Products with O(1) Space):
1. We can optimize the space complexity by using the output array to store the left products and a variable to keep track of the right product.
2. First, we fill the output array with the left products.
3. Then, we iterate through the array from the end to the beginning, updating the output array with the product of the left product (already stored in the output array) and the right product (stored in a variable). We also update the right product variable as we go.

Space Complexity: O(1)
Time Complexity: O(n)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }

        int rightProduct = 1;
        for (int i = n-2; i >= 0; i--) {
            rightProduct *= nums[i+1];
            ans[i] *= rightProduct;
        }
        
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    vector<int> nums1 = {1,2,3,4};
    vector<int> ans1 = solution.productExceptSelf(nums1);
    printVec(ans1);

    vector<int> nums2 = {-1,1,0,-3,3};
    vector<int> ans2 = solution.productExceptSelf(nums2);
    printVec(ans2);

    vector<int> nums3 = {0,0};
    vector<int> ans3 = solution.productExceptSelf(nums3);
    printVec(ans3);
    
    return 0;
}