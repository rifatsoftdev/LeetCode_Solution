#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


class Solution {
public:
    int binarySearch(vector<int>& arr, int num, char c) {
        int start = 0, end = arr.size() - 1;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (num == arr[mid]) {
                ans = mid;
                if (c == 'L') end = mid - 1;
                else if (c == 'R') start = mid + 1;
            }
            else if (num < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        return {
            binarySearch(nums, target, 'L'),
            binarySearch(nums, target, 'R')
        };
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> result1 = solution.searchRange(nums1, target1);
    cout << "[" << result1[0] << ", " << result1[1] << "]" << endl; // Output: [3, 4]

    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    vector<int> result2 = solution.searchRange(nums2, target2);
    cout << "[" << result2[0] << ", " << result2[1] << "]" << endl; // Output: [-1, -1]

    return 0;
}