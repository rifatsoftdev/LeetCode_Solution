#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    string interpret(string command) {
        string result;

        for (int i = 0; i < command.size(); ++i) {
            if (command[i] == 'G') {
                result += 'G';
            } else if (command[i] == '(' && i + 1 < command.size() && command[i + 1] == ')') {
                result += "o";
                i++;
            } else if (command[i] == '(' && i + 3 < command.size() && command[i + 1] == 'a' && command[i + 2] == 'l' && command[i + 3] == ')') {
                result += "al";
                i += 3;
            }
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string command1 = "G()(al)";
    cout << solution.interpret(command1) << endl;

    // test cases 2
    string command2 = "G()()()()(al)";
    cout << solution.interpret(command2) << endl;

    // test cases 3
    string command3 = "(al)G(al)()()G";
    cout << solution.interpret(command3) << endl;

    return 0;
}