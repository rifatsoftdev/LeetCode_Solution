#include <iostream>
#include <vector>
#include <algorithm>
#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> magazineMap;
        for (char c : magazine) {
            magazineMap[c]++;
        }

        for (char c : ransomNote) {
            if (magazineMap[c] == 0) {
                return false;
            }
            magazineMap[c]--;
        }

        return true;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}