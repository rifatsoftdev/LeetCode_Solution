#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {};
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> numbers1 = {2,7,11,15};
    int target1 = 9;
    printVec(solution.twoSum(numbers1, target1));

    // test cases 2
    vector<int> numbers2 = {2,3,4};
    int target2 = 6;
    printVec(solution.twoSum(numbers2, target2));

    // test cases 3
    vector<int> numbers3 = {-1,0};
    int target3 = -1;
    printVec(solution.twoSum(numbers3, target3));
    
    return 0;
}