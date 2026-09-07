#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int ans = 0;
        int n = arr.size();

        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        int left = 0;
        int right = k - 1;

        while (right < n) {
            if (sum >= threshold * k) {
                ans++;
            }

            sum -= arr[left];
            right++;

            if (right < n) {
                sum += arr[right];
            }

            left++;
            
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> arr1 = {2,2,2,2,5,5,5,8};
    int k1 = 3, threshold1 = 4;
    cout << solution.numOfSubarrays(arr1, k1, threshold1) << endl;

    // test cases 2
    vector<int> arr2 = {11,13,17,23,29,31,7,5,2,3};
    int k2 = 3, threshold2 = 5;
    cout << solution.numOfSubarrays(arr2, k2, threshold2) << endl;

    return 0;
}