#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Optimal Substructure (Backtracking):
1. Define a recursive function that takes the current starting index, the current path of palindromic substrings, and the final result vector.
2. If the starting index reaches the end of the string, add the current path to the result vector.
3. Iterate through the string from the starting index to the end, checking if the substring from the starting index to the current index is a palindrome.
4. If it is a palindrome, add it to the current path and recursively call the function with the next starting index (current index + 1).
5. After the recursive call, backtrack by removing the last added substring from the current path and continue checking for the next possible palindromic substring.

Time Complexity: O(N * 2^N) - In the worst case, we may have to explore all possible partitions of the string, which can be exponential in nature. Additionally, checking if a substring is a palindrome takes O(N) time.
Space Complexity: O(N) - The space complexity is O(N) for the recursion stack and O(N) for the path vector that stores the current partitioning. The result vector can also grow up to O(N) in the worst case, but it is not counted towards the space complexity as it is the output of the function.
*/

class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void backtracking(const string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                backtracking(s, i + 1, path, result);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;

        backtracking(s, 0, path, result);

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<string>> result1 = solution.partition("aab");
    printVec2D(result1);

    vector<vector<string>> result2 = solution.partition("a");
    printVec2D(result2);

    return 0;
}