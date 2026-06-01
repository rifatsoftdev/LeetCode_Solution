#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int minDiff = INT_MAX;

        for (int i = 1; i < arr.size(); i++) {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i-1] == minDiff) {
                ans.push_back({arr[i-1], arr[i]});
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector arr1 = {4,2,1,3};
    vector<vector<int>> ans1 = solution.minimumAbsDifference(arr1);
    printVec2D(ans1);

    // test cases 2
    vector arr2 = {1,3,6,10,15};
    vector<vector<int>> ans2 = solution.minimumAbsDifference(arr2);
    printVec2D(ans2);

    // test cases 3
    vector arr3 = {3,8,-10,23,19,-4,-14,27};
    vector<vector<int>> ans3 = solution.minimumAbsDifference(arr3);
    printVec2D(ans3);

    return 0;
}