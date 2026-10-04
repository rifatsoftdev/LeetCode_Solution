#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        map<string, int> wordCount;

        for (const string& word : words) {
            wordCount[word]++;
        }

        for (const auto& entry : wordCount) {
            if (entry.second == k) {
                result.push_back(entry.first);
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
    vector<string> words1 = {"i", "love", "leetcode", "i", "love", "coding"};
    int k1 = 2;
    vector<string> result1 = solution.topKFrequent(words1, k1);
    printVec(result1);

    // test cases 2
    vector<string> words2 = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    int k2 = 4;
    vector<string> result2 = solution.topKFrequent(words2, k2);
    printVec(result2);

    return 0;
}