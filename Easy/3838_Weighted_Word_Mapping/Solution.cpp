#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";

        for (int i = 0; i < words.size(); i++) {
            int num = 0;

            for (int j = 0; j < words[i].size(); j++) {
                num += weights[words[i][j] - 'a'];
            }

            result += 'z' - num % 26;
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<string> words1 = {"abcd","def","xyz"};
    vector<int> weights1 = {5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2};
    cout << solution.mapWordWeights(words1, weights1) << endl;  // Output: "rij"

    // test cases 2
    vector<string> words2 = {"a","b","c"};
    vector<int> weights2 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    cout << solution.mapWordWeights(words2, weights2) << endl;  // Output: "yyy"

    // test cases 3
    vector<string> words3 = {"abcd"};
    vector<int> weights3 = {7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5};
    cout << solution.mapWordWeights(words3, weights3) << endl;  // Output: "g"

    return 0;
}