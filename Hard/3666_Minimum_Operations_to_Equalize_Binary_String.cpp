#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "../devlibs/cpphelper.h"

using namespace std;


/*

*/

class Solution {
public:
    int minOperations(string s, int k) {
        int zero = 0;
        int len = s.length();

        for (int i = 0; i < len; i++)
            zero += ~s[i] & 1;

        if (!zero)
            return 0;

        if (len == k)
            return ((zero == len) << 1) - 1;

        int base = len - k;

        int odd = max(
            (zero + k - 1) / k,
            (len - zero + base - 1) / base
        );

        odd += ~odd & 1;

        int even = max(
            (zero + k - 1) / k,
            (zero + base - 1) / base
        );

        even += even & 1;

        int res = INT_MAX;

        if ((k & 1) == (zero & 1))
            res = min(res, odd);

        if (~zero & 1)
            res = min(res, even);

        return res == INT_MAX ? -1 : res;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.minOperations("110", 1) << endl; // 1
    cout << solution.minOperations("0101", 3) << endl; // 2
    cout << solution.minOperations("101", 2) << endl; // -1

    return 0;
}