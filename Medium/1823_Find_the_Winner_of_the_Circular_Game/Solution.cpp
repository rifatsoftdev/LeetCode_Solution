#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.



/* ================================================================================
Solution 1:

Find the winner of the circular game:
    1. Start with a list of players numbered from 1 to n.
    2. Begin with the first player and count k players in a clockwise direction.
    3. The player at the kth position is eliminated from the game.
    4. Repeat the process with the remaining players, starting from the next player after the eliminated one, until only one player remains. The last remaining player is the winner.

Time Complexity: O(n * k)
Space Complexity: O(n)
*/

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> isAlive(n, 1);
        int aliveCount = n;
        int currentIndex = 0;

        while (aliveCount > 1) {
            int count = 0;

            while (count < k) {
                if (isAlive[currentIndex]) {
                    count++;
                }

                if (count == k) {
                    break;
                }

                currentIndex = (currentIndex + 1) % n;
            }

            isAlive[currentIndex] = 0;
            aliveCount--;

            currentIndex = (currentIndex + 1) % n;
        }

        for (int i = 0; i < n; i++) {
            if (isAlive[i]) {
                return i + 1;
            }
        }

        return -1;
    }
};


/* ================================================================================
Solution 2:

Find the winner of the circular game:
    1. Start with a list of players numbered from 1 to n.
    2. Begin with the first player and count k players in a clockwise direction.
    3. The player at the kth position is eliminated from the game.
    4. Repeat the process with the remaining players, starting from the next player after the eliminated one, until only one player remains. The last remaining player is the winner.

Time Complexity: O(n)
Space Complexity: O(1)
*/

// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         int winner = 0;

//         for (int i = 2; i <= n; i++) {
//             winner = (winner + k) % i;
//         }

//         return winner + 1;
//     }
// };


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    cout << solution.findTheWinner(5, 2) << endl; // 3
    cout << solution.findTheWinner(6, 5) << endl; // 1

    return 0;
}