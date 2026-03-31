#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

*/

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {1,3,8,48,10};
    cout << solution.longestNiceSubarray(nums1) << endl;

    vector<int> nums2 = {3,1,5,11,13};
    cout << solution.longestNiceSubarray(nums2) << endl;

    return 0;
}