#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int smallestEvenMultiple(int n) {
        if (n % 2 == 0) return n;
        return n * 2;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.smallestEvenMultiple(5) << endl;  // Expected: 10
    
    // test cases 2
    cout << solution.smallestEvenMultiple(6) << endl;  // Expected: 6

    return 0;
}