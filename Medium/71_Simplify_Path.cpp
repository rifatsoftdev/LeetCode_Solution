#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

*/

class Solution {
public:
    string simplifyPath(string path) {
        
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.simplifyPath("/home/") << endl;
    cout << solution.simplifyPath("/home//foo/") << endl;
    cout << solution.simplifyPath("/home/user/Documents/../Pictures") << endl;
    cout << solution.simplifyPath("/../") << endl;
    cout << solution.simplifyPath("/.../a/../b/c/../d/./") << endl;


    return 0;
}