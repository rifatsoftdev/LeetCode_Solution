#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minutesAng = minutes * 6.0;
        double hourAng = (hour * 30.0) + (minutes * 0.5);
        double diff = abs(minutesAng - hourAng);
        return min(diff, 360.0 - diff);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    int hour1 = 12, minutes1 = 30;
    cout << solution.angleClock(hour1, minutes1) << endl;
    
    // test cases 2
    int hour2 = 3, minutes2 = 30;
    cout << solution.angleClock(hour2, minutes2) << endl;
    
    // test cases 3
    int hour3 = 3, minutes3 = 15;
    cout << solution.angleClock(hour3, minutes3) << endl;

    return 0;
}