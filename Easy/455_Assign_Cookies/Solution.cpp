#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0;
        int cookie = 0;

        while (child < g.size() && cookie < s.size()) {

            if (s[cookie] >= g[child]) {
                child++;
            }

            cookie++;
        }

        return child;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};
    cout << solution.findContentChildren(g1, s1) << endl;
    
    // test cases 2
    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};
    cout << solution.findContentChildren(g2, s2) << endl;
    
    return 0;
}