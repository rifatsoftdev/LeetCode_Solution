#include "../../devlibs/cpp/cpphelper.h"


using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


string toBinary(int n) {
    if (n == 0) return "0";

    string res = "";
    while (n > 0) {
        res += (n % 2) ? '1' : '0';
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

class Solution {
public:
    string convertDateToBinary(string date) {
        stringstream ss(date);
        string year, month, day;

        getline(ss, year, '-');
        getline(ss, month, '-');
        getline(ss, day, '-');

        return toBinary(stoi(year)) + "-" +
               toBinary(stoi(month)) + "-" +
               toBinary(stoi(day));
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string date1 = "2080-02-29";
    cout << solution.convertDateToBinary(date1) << endl;
    
    // test cases 2
    string date2 = "1900-01-01";
    cout << solution.convertDateToBinary(date2) << endl;
    

    return 0;
}