#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

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


/* ================================================================================
Solution 1:

Post Order Traversal:
    1. Postorder traversal is a depth-first traversal method for binary trees.
    2. In postorder traversal, the nodes are visited in the following order:
    a. Traverse the left subtree first.
    b. Traverse the right subtree.
    c. Visit the root node last.
    3. The result of a postorder traversal is a list of node values in the order they were visited.
    4. Postorder traversal can be implemented using recursion or an iterative approach with a stack.

Time Complexity: O(n), where n is the number of nodes in the binary tree, since we visit each node exactly once.
Space Complexity: O(n) in the worst case (when the tree is completely unbalanced), and O(log n) in the best case (when the tree is balanced), due to the recursive call stack.
*/

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