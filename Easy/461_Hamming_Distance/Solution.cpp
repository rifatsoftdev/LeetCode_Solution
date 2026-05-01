#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        string x_bin = bitset<32>(x).to_string();
        string y_bin = bitset<32>(y).to_string();
        int distance = 0;

        for (int i = 0; i < 32; i++) {
            if (x_bin[i] != y_bin[i]) {
                distance++;
            }
        }

        return distance;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.hammingDistance(1, 4) << endl; // Output: 2
    cout << solution.hammingDistance(3, 1) << endl; // Output: 1

    return 0;
}