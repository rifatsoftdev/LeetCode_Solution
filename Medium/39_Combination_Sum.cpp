#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Combination Sum (Backtracking):
    1. Use a recursive backtracking function to explore all possible combinations of numbers that sum up to the target.
    2. At each step, you have two choices: include the current element (and potentially include it again since elements can be reused) or skip to the next element.
    3. If the target becomes 0, a valid combination is found and added to the result.
    4. If the target becomes negative or we run out of elements, terminate that branch of recursion.
    5. Use a set or sort the input to handle potential duplicate combinations if necessary.

Time Complexity: O(2^t * k), where t is the target value and k is the average length of a combination.
Space Complexity: O(target/min_element) for the recursion stack. 
*/

class Solution {
private:
    set<vector<int>> s;

    void getAllCombination(vector<int> &arr, int idx, int target, vector<vector<int>> &ans, vector<int> &combin) {
        if (idx == arr.size() || target < 0) {
            return;
        }

        if (target == 0) {
            if (s.find(combin) == s.end()) {
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }

        combin.push_back(arr[idx]);
        // single
        getAllCombination(arr, idx+1, target-arr[idx], ans, combin);
        // multiple
        getAllCombination(arr, idx, target-arr[idx], ans, combin);
        // exclusion
        combin.pop_back();
        getAllCombination(arr, idx+1, target, ans, combin);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombination(arr, 0, target, ans, combin);
        
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> candidates1 = {2,3,5};
    vector<vector<int>> result1 = solution.combinationSum(candidates1, 8);
    printVec2D(result1);



    return 0;
}