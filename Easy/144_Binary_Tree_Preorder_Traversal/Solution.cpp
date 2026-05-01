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

Binary Tree Preorder Traversal:
    1. Preorder traversal is a depth-first traversal method for binary trees.
    2. In preorder traversal, the nodes are visited in the following order:
    a. Visit the root node first.
    b. Traverse the left subtree.
    c. Traverse the right subtree.
    3. The result of a preorder traversal is a list of node values in the order they were visited.
    4. Preorder traversal can be implemented using recursion or an iterative approach with a stack.

Time Complexity: O(n), where n is the number of nodes in the binary tree, since we visit each node exactly once.
Space Complexity: O(n) in the worst case (when the tree is completely unbalanced), and O(log n) in the best case (when the tree is balanced), due to the recursive call stack.
*/

class Solution {
private:
    vector<int> ans;
    void preorder(TreeNode* root) {
        if (root == NULL) return;

        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(2);
    
    root->right->left = new TreeNode(3);

    vector<int> ans = solution.preorderTraversal(root);
    printVec(ans);

    return 0;
}