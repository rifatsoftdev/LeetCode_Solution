#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int common_cnt = 0;
        vector<int> ans;
        set<int> seen;

        for (int i = 0; i < n; i++) {
            if (seen.find(A[i]) != seen.end()) {
                common_cnt++;
            } else {
                seen.insert(A[i]);
            }

            if (seen.find(B[i]) != seen.end()) {
                common_cnt++;
            } else {
                seen.insert(B[i]);
            }

            ans.push_back(common_cnt);
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> A1 = {1,3,2,4};
    vector<int> B1 = {3,1,2,4};
    vector<int> C1 = solution.findThePrefixCommonArray(A1, B1);
    printVec(C1);

    // test cases 2
    vector<int> A2 = {2,3,1};
    vector<int> B2 = {3,1,2};
    vector<int> C2 = solution.findThePrefixCommonArray(A2, B2);
    printVec(C2);

    return 0;
}