#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxC = *max_element(candies.begin(), candies.end());
        vector<bool> result;

        for (int c : candies) {
            result.push_back(c + extraCandies >= maxC);
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> candies1 = {2,3,5,1,3};
    int extraCandies1 = 3;
    vector<bool> result1 = solution.kidsWithCandies(candies1, extraCandies1);
    printVec(result1);

    // test cases 2
    vector<int> candies2 = {4,2,1,1,2};
    int extraCandies2 = 1;
    vector<bool> result2 = solution.kidsWithCandies(candies2, extraCandies2);
    printVec(result2);

    // test cases 3
    vector<int> candies3 = {12,1,12};
    int extraCandies3 = 10;
    vector<bool> result3 = solution.kidsWithCandies(candies3, extraCandies3);
    printVec(result3);

    return 0;
}