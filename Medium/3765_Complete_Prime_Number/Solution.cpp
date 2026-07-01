#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
private:
    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }

public:
    bool completePrime(int num) {
        string s = to_string(num);

        for (int i = 1; i <= s.size(); i++) {
            long long prefix = stoll(s.substr(0, i));
            if (!isPrime(prefix)) return false;
        }

        for (int i = 0; i < s.size(); i++) {
            long long suffix = stoll(s.substr(i));
            if (!isPrime(suffix)) return false;
        }

        return true;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << (solution.completePrime(23) ? "true" : "false") << endl;
    
    // test cases 2
    cout << (solution.completePrime(39) ? "true" : "false") << endl;

    // test cases 3
    cout << (solution.completePrime(7) ? "true" : "false") << endl;

    return 0;
}