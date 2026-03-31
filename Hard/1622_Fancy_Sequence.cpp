#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Fancy Sequence (Mathematical / Modular Inverse):
    1. The problem requires performing range updates (addition and multiplication) and point queries on a sequence.
    2. Instead of updating every element, we maintain global `mul` and `add` variables to represent the cumulative transformations: `val = (original * mul) + add`.
    3. When `addAll(inc)` is called, we update `add = (add + inc) % mod`.
    4. When `multAll(m)` is called, we update both `mul = (mul * m) % mod` and `add = (add * m) % mod`.
    5. To `append(val)`, we must store a value `x` such that `(x * current_mul) + current_add = val`. This is achieved using the modular multiplicative inverse: `x = (val - current_add) * inv(current_mul) % mod`.
    6. `getIndex(idx)` simply computes `(stored_x * current_mul + current_add) % mod`.

Time Complexity: O(1) for append, addAll, multAll; O(log MOD) for getIndex (due to modular inverse in append).
Space Complexity: O(N) to store the sequence.
*/

class Fancy {
public:
    vector<long long> arr;
    long long mul = 1, add = 0;
    const long long mod = 1000000007;

    long long modPow(long long a, long long b) {
        long long res = 1;
        a %= mod;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long x) {
        return modPow(x, mod - 2);
    }

    Fancy() {
        
    }
    
    void append(int val) {
        long long x = (val - add) % mod;
        if (x < 0) x += mod;
        x = (x * modInverse(mul)) % mod;
        arr.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add + inc) % mod;
    }
    
    void multAll(int m) {
        mul = (mul * m) % mod;
        add = (add * m) % mod;
    }
    
    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        return (arr[idx] * mul + add) % mod;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    return 0;
}