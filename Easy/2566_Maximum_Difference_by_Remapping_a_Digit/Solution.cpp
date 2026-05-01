#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxNum = "";
        string minNum = "";
        char fastNum = '0';
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] != '9') {
                fastNum = s[i];
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == fastNum) {
                maxNum += '9';
            } else {
                maxNum += s[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                fastNum = s[i];
                break;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (s[i] == fastNum) {
                minNum += '0';
            } else {
                minNum += s[i];
            }
        }

        return stoi(maxNum) - stoi(minNum);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    // test cases 1
    cout << solution.minMaxDifference(11891) << endl; // Output: 99009

    // test cases 2
    cout << solution.minMaxDifference(90) << endl; // Output: 99

    return 0;
}