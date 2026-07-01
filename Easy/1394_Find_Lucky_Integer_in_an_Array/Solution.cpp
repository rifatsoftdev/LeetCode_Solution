#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> m;

        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]]++;
        }

        int large_num = -1;

        for (auto const& [key, val] : m) {
            if (key == val && val > large_num) {
                large_num = val;
            }
        }

        return large_num;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> arr1 = {2, 2, 3, 4};
    cout << solution.findLucky(arr1) << endl;
    
    // test cases 2
    vector<int> arr2 = {1, 2, 2, 3, 3, 3};
    cout << solution.findLucky(arr2) << endl;

    // test cases 3
    vector<int> arr3 = {2, 2, 2, 3, 3};
    cout << solution.findLucky(arr3) << endl;
    

    return 0;
}