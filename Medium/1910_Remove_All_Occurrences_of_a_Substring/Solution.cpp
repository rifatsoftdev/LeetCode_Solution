#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.size() > 0 && s.find(part) < s.size() ) {
            s.erase(s.find(part), part.size());
        }

        return s;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string s1 = "daabcbaabcbc";
    string part1 = "abc";
    cout << solution.removeOccurrences(s1, part1) << endl;

    // test cases 2
    string s2 = "axxxxyyyyb";
    string part2 = "xy";
    cout << solution.removeOccurrences(s2, part2) << endl;

    return 0;
}