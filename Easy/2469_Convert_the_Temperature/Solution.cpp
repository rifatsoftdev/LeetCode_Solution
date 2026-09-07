#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kelvin = celsius + 273.15;
        double fahrenheit = celsius * 1.80 + 32.00;

        return {kelvin, fahrenheit};
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    double celsius1 = 36.50;
    vector<double> result1 = solution.convertTemperature(celsius1);
    printVec(result1);

    // test cases 2
    double celsius2 = 122.11;
    vector<double> result2 = solution.convertTemperature(celsius2);
    printVec(result2);

    return 0;
}