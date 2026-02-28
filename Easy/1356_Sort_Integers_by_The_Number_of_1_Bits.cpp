#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Brute Force Approach (Counting and Sorting):
1. Count the number of '1' bits for each integer in the array.
2. Sort the integers based on the count of '1' bits and then by their values.

Time Complexity: O(n log n) (due to sorting)
Space Complexity: O(n) (due to the map storing the integers based on their '1' bit counts)
*/

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int, vector<int>> bit;
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {
            int b = __builtin_popcount(arr[i]);
            bit[b].push_back(arr[i]);
        }

        for(auto &p : bit) {
            sort(p.second.begin(), p.second.end());
            for(int x : p.second) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> arr1 = {0,1,2,3,4,5,6,7,8};
    vector<int> ans1 = solution.sortByBits(arr1);
    printVec(ans1);

    vector<int> arr2 = {1024,512,256,128,64,32,16,8,4,2,1};
    vector<int> ans2 = solution.sortByBits(arr2);
    printVec(ans2);

    vector<int> arr3 = {2,3,5,7,11,13,17,19};
    vector<int> ans3 = solution.sortByBits(arr3);
    printVec(ans3);

    return 0;
}