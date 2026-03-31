#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Reverse Pairs (Brute Force):
    1. Use two nested loops to iterate through all possible pairs (i, j) such that 0 <= i < j < nums.length.
    2. For each pair, check if the condition nums[i] > 2 * nums[j] is satisfied.
    3. If the condition is met, increment the count of reverse pairs.
    4. Return the total count of reverse pairs.

Time Complexity: O(n^2)
Space Complexity: O(1)

Note: This approach will result in a Time Limit Exceeded (TLE) error for large inputs.
*/

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        long long reversePairsCount = 0;

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] > 2*(long long)nums[j]){
                    reversePairsCount++;
                }
            }
        }
        
        return reversePairsCount;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}