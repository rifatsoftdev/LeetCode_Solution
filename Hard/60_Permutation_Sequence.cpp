#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Brute Force Approach (Backtracking):
1. Generate all permutations of the numbers from 1 to n.
2. Sort the permutations and return the k-th permutation.

Time Complexity: O(n! * n) due to generating all permutations and sorting them.
Space Complexity: O(n! * n) for storing all permutations.
*/

// class Solution {
// public:
//     void getPermute(vector<char>& s, int idx, vector<vector<char>>& ans) {
//         if (idx == s.size()) {
//             ans.push_back(s);
//             return;
//         }
//         for (int i = idx; i < s.size(); i++) {
//             swap(s[idx], s[i]);
//             getPermute(s, idx+1, ans);
//             swap(s[idx], s[i]);
//         }
//     }

//     string getPermutation(int n, int k) {
//         vector<char> s;
//         for (int i = 1; i <= n; i++) s.push_back('0'+i);

//         vector<vector<char>> ans;
//         getPermute(s, 0, ans);
        
//         string sans = "";
//         for (int i = 0; i< ans[k-1].size(); i++) sans+=ans[k-1][i];

//         return sans;

//     }
// };


/*
Optimal Approach (Factorial Number System):
1. We can use the factorial number system to find the k-th permutation directly without generating all permutations.
2. We first calculate the factorial values for numbers from 0 to n-1.
3. We then determine the index of the next number to add to our permutation by dividing k by the factorial of the remaining digits.
4. We update k to find the next index for the remaining digits and repeat the process until we have our complete permutation.

Time Complexity: O(n^2) due to the erase operation on the vector.
Space Complexity: O(n) for storing the numbers and factorial values.
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i = 1; i <= n; i++)
            nums.push_back(i);

        vector<int> fact(n);
        fact[0] = 1;
        for(int i = 1; i < n; i++)
            fact[i] = fact[i-1] * i;

        k--; // zero-based index

        string ans = "";

        for(int i = n; i >= 1; i--) {
            int index = k / fact[i-1];
            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k %= fact[i-1];
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    cout << solution.getPermutation(3, 3) << endl;
    cout << solution.getPermutation(4, 9) << endl;
    cout << solution.getPermutation(3, 1) << endl;
    cout << solution.getPermutation(3, 5) << endl;
    

    return 0;
}