#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Two Furthest Houses With Different Colors:
    1. We need to find the maximum distance between two houses with different colors.
    2. A brute force approach involves checking every pair of houses (i, j) and calculating the distance |i - j| if their colors are different.
    3. Alternatively, since we want to maximize the distance, the optimal house must be paired with either the first house or the last house.
    4. We can iterate from the end of the array to find the first house with a different color than `colors[0]`, and iterate from the beginning to find the first house with a different color than `colors[n-1]`.
    5. The maximum of these two distances will be the answer.

Time Complexity: O(n), where n is the number of houses.
Space Complexity: O(1).
*/

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = n-1; j > i; j--) {
                if (colors[i] != colors[j]) {
                    ans = max(ans, j-i);
                }
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> colors1 = {1,1,1,6,1,1,1};
    cout << solution.maxDistance(colors1) << endl;

    vector<int> colors2 = {1,8,3,8,3};
    cout << solution.maxDistance(colors2) << endl;

    vector<int> colors3 = {10,1};
    cout << solution.maxDistance(colors3) << endl;

    return 0;
}