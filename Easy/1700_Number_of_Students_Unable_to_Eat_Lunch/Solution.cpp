#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zero = 0;
        int one = 0;

        for (int student : students) {
            if (student == 0)
                zero++;
            else
                one++;
        }

        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (zero == 0)
                    return one;
                zero--;
            } else {
                if (one == 0)
                    return zero;
                one--;
            }
        }

        return 0;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> students1 = {1,1,0,0};
    vector<int> sandwiches1 = {0,1,0,1};
    cout << solution.countStudents(students1, sandwiches1) << endl;

    // test cases 2
    vector<int> students2 = {1,1,1,0,0,1};
    vector<int> sandwiches2 = {1,0,0,0,1,1};
    cout << solution.countStudents(students2, sandwiches2) << endl;

    return 0;
}