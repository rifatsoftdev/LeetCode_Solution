#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
*/

class Solution {
private:
    int count = 0;

    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0}; // {sum, count}

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        int sum = left.first + right.first + node->val;
        int cnt = left.second + right.second + 1;

        if (node->val == sum / cnt) {
            count++;
        }

        return {sum, cnt};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        this->count = 0;

        dfs(root);

        return this->count;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    // test cases 2

    return 0;
}