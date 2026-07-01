#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
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
    vector<int> players1 = {4, 7, 9};
    vector<int> trainers1 = {8, 2, 5, 8};
    cout << solution.matchPlayersAndTrainers(players1, trainers1) << endl;

    // test cases 2
    vector<int> players2 = {1, 1, 1};
    vector<int> trainers2 = {10};
    cout << solution.matchPlayersAndTrainers(players2, trainers2) << endl;
    
    return 0;
}