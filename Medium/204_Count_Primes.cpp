#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Optimal Solution (Sieve of Eratosthenes):
1. We can use the Sieve of Eratosthenes algorithm to find all prime numbers less than n efficiently.
2. We create a boolean vector initialized to true, where the index represents the number and the value represents whether it is prime or not.
3. We mark 0 and 1 as non-prime. Then, we iterate through the vector starting from 2. For each prime number found, we mark all of its multiples as non-prime.
4. Finally, we count the number of true values in the vector, which represents the count of prime numbers less than n.

Space Complexity: O(n)
Time Complexity: O(n log log n)
*/

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        return count(isPrime.begin(), isPrime.end(), true);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.countPrimes(10) << endl;
    cout << solution.countPrimes(0) << endl;
    cout << solution.countPrimes(1) << endl;

    return 0;
}