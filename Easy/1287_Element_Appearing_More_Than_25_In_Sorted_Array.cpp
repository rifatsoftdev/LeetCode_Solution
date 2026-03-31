#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Element Appearing More Than 25% In Sorted Array:
    1. Use a hash map to store the frequency of each element in the array.
    2. Iterate through the array and increment the count for each element in the map.
    3. For each element, check if its count has exceeded the threshold of 25% of the total array size (n / 4).
    4. Return the first element that meets this criteria.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;

            if (mp[arr[i]] > n / 4) {
                return arr[i];
            }
        }

        return -1;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> arr1 = {1,2,2,6,6,6,6,7,10};
    cout << solution.findSpecialInteger(arr1) << endl;

    vector<int> arr2 = {1,1};
    cout << solution.findSpecialInteger(arr2) << endl;

    return 0;
}