#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int result = 0;
//         int n = height.size();

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 result = max(result, min(height[i], height[j]) * (j - i));
//             }
//         }

//         return result;
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int w = right - left;
            int h = min(height[left], height[right]);
            int a = w * h;

            result = max(result, a);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> height1 = {1,8,6,2,5,4,8,3,7};
    cout << solution.maxArea(height1) << endl;

    // test cases 2
    vector<int> height2 = {1,1};
    cout << solution.maxArea(height2) << endl;

    return 0;
}