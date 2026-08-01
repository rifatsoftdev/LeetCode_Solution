#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    int gcdOfOddEvenSums(int n) {
        int oddSum = 0, evenSum = 0;

        for (int i = 1; i <= n*2; i += 2) {
            oddSum += i;
        }

        for (int i = 2; i <= n*2; i += 2) {
            evenSum += i;
        }

        return gcd(oddSum, evenSum);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.gcdOfOddEvenSums(4) << endl;

    // test cases 2
    cout << solution.gcdOfOddEvenSums(5) << endl;

    return 0;
}