#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
private:
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }

public:
    int maximumPrimeDifference(vector<int>& nums) {
        
        int left_prime = -1;
        int right_prime = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (isPrime(nums[i])) {
                left_prime = i;
                break;
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (isPrime(nums[i])) {
                right_prime = i;
                break;
            }
        }
        
        return right_prime - left_prime;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {4,2,9,5,3};
    cout << solution.maximumPrimeDifference(nums1) << endl; // 3

    // test cases 2
    vector<int> nums2 = {4,8,2,8};
    cout << solution.maximumPrimeDifference(nums2) << endl; // 0

    return 0;
}