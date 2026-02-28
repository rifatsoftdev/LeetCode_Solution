#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Optimal Solution (Fast Exponentiation):
1. We can use the fast exponentiation method (also known as exponentiation by squaring) to compute x^n efficiently.
2. If n is even, we can compute x^n as (x^(n/2))^2.
3. If n is odd, we can compute x^n as (x^(n//2))^2 * x.
4. If n is negative, we can compute x^n as 1 / (x^(-n)).
5. We can implement this using recursion or iteration.

Space Complexity: O(1)
Time Complexity: O(n^3)
*/

class Solution {
public:
    double findPow(double x, int n) {
        if (n == 0) return 1;

        double a = findPow(x, n/2);
        if (n % 2 == 0) return a*a;
        else return a*a*x;
    }

    double myPow(double x, int n) {
        if (n == 0) return 1;
        else if (n > 0) return findPow(x, n);
        else {
            long nn = n;
            nn *= -1;
            return 1 / findPow(x, n);
        }
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.myPow(2.00000, 10) << endl;
    cout << solution.myPow(2.10000, 3) << endl;
    cout << solution.myPow(2.00000, -2) << endl;

    return 0;
}