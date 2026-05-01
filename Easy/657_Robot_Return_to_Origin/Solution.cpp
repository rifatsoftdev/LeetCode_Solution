#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Robot Return to Origin:
    1. Create a map to count the occurrences of each move.
    2. Iterate through the moves and update the counts in the map.
    3. Check if the count of 'U' equals the count of 'D' and the count of 'L' equals the count of 'R'.
    4. If both conditions are satisfied, return true; otherwise, return false.

Time Complexity: O(n), where n is the length of the moves string.
Space Complexity: O(1), since the map will only contain a fixed number of keys ('U', 'D', 'L', 'R').
*/

// class Solution {
// public:
//     bool judgeCircle(string moves) {
//         map<char, int> map;

//         for (int i = 0; i < moves.size(); i++) {
//             map[moves[i]]++;
//         }

//         return map['U'] == map['D'] && map['L'] == map['R'];
//     }
// };



/* ================================================================================
Solution 2:

Robot Return to Origin:
    1. Create a vector of size 4 to count the occurrences of each move (U, D, L, R).
    2. Iterate through the moves and update the counts in the vector based on the move character.
    3. Check if the count of 'U' equals the count of 'D' and the count of 'L' equals the count of 'R'.
    4. If both conditions are satisfied, return true; otherwise, return false.

Time Complexity: O(n), where n is the length of the moves string.
Space Complexity: O(1), since the vector will only contain a fixed number of elements (4).
*/

class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> vce(4, 0); // U, D, L, R

        for (char c : moves) {
            if (c == 'U') vce[0]++;
            else if (c == 'D') vce[1]++;
            else if (c == 'L') vce[2]++;
            else if (c == 'R') vce[3]++;
        }

        return vce[0] == vce[1] && vce[2] == vce[3];
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.judgeCircle("UD") << endl; // true
    cout << solution.judgeCircle("LL") << endl; // false

    return 0;
}