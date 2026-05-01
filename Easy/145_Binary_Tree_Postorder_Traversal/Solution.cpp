#include <iostream>
#include <vector>
#include <algorithm>
#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


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


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
private:
    void postorder(TreeNode* root, vector<int> &ans) {
        if (root == NULL) return;
        
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ans = solution.postorderTraversal(root);
    printVec(ans);

    return 0;
}