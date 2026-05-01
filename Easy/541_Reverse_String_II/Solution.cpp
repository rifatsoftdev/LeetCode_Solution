#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Reverse String II:
    1. You are given a string s and an integer k.
    2. You need to reverse the first k characters for every 2k characters counting from the start of the string.
    3. If there are fewer than k characters left, reverse all of them. If there are between k and 2k characters, then reverse the first k characters and leave the others as original.

Time Complexity: O(n), where n is the length of the input string s. We are iterating through the string once and performing a constant amount of work for each character.
Space Complexity: O(1), as we are modifying the string in place and not using any additional data structures that grow with the input size.
*/

class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();

        for (int i = 0; i < n; i += 2*k){
            int left=i;
            int right=min(i+k-1,n-1);

            while (left < right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.reverseStr("abcdefg", 2) << endl; // Output: "bacdfeg"
    cout << solution.reverseStr("abcd", 2) << endl;    // Output: "bacd"

    return 0;
}