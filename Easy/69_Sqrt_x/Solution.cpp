#include <iostream>
#include <vector>
#include <algorithm>
#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) 
            return x;

        long long start = 0, end = x/2, ans;

        while (start <= end) {
            long long mid = (start + end) / 2;

            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    // test cases 1
    cout << solution.mySqrt(4) << endl; // Output: 2

    // test cases 2
    cout << solution.mySqrt(8) << endl; // Output: 2

    return 0;
}