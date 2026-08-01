#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int gcd(int a, int b) {
        while (b) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        vector<int> prefix;

        int mx = 0;

        for (int x : nums) {
            mx = max(mx, x);
            prefix.push_back(gcd(x, mx));
        }

        sort(prefix.begin(), prefix.end());

        long long ans = 0;

        int l = 0;
        int r = prefix.size() - 1;

        while (l < r) {
            ans += gcd(prefix[l], prefix[r]);
            l++;
            r--;
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {2,6,4};
    cout << solution.gcdSum(nums1) << endl;

    // test cases 2
    vector<int> nums2 = {3,6,2,8};
    cout << solution.gcdSum(nums2) << endl;

    return 0;
}