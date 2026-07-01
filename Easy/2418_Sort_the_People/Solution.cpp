#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        for (int i = 0; i < heights.size(); i++) {
            int maxIdx = i;

            for (int j = i; j < heights.size(); j++) {
                if (heights[maxIdx] < heights[j]) 
                    maxIdx = j;
            }

            swap(heights[i], heights[maxIdx]);
            swap(names[i], names[maxIdx]);
        }

        return names;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<string> names1 = {"Mary","John","Emma"};
    vector<int> heights1 = {180,165,170};
    vector<string> result1 = solution.sortPeople(names1, heights1);
    printVec(result1);

    // test cases 2
    vector<string> names2 = {"Alice","Bob","Bob"};
    vector<int> heights2 = {155,185,150};
    vector<string> result2 = solution.sortPeople(names2, heights2);
    printVec(result2);

    return 0;
}