#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;

        for (int i = 0; i < list1.size(); i++) {
            mp[list1[i]] = i;
        }

        int mn = INT_MAX;
        vector<string> ans;

        for (int i = 0; i < list2.size(); i++) {

            if (mp.count(list2[i])) {
                int sum = mp[list2[i]] + i;

                if (sum < mn) {
                    mn = sum;
                    ans.clear();
                    ans.push_back(list2[i]);
                }
                else if (sum == mn) {
                    ans.push_back(list2[i]);
                }
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<string> list11 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list12 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};
    vector<string> ans1 = solution.findRestaurant(list11, list12);
    printVec(ans1);

    // test cases 2
    vector<string> list21 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list22 = {"KFC","Shogun","Burger King"};
    vector<string> ans2 = solution.findRestaurant(list21, list22);
    printVec(ans2);

    // test cases 3
    vector<string> list31 = {"happy","sad","good"};
    vector<string> list32 = {"sad","happy","good"};
    vector<string> ans3 = solution.findRestaurant(list31, list32);
    printVec(ans3);

    return 0;
}