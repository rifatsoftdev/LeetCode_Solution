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

Ballanced Binary Tree:

1. A binary tree is height-balanced if the left and right subtrees of every node differ in height by no more than 1.
    2. Use a recursive approach to calculate the height of each subtree.
    3. If at any node the difference in heights of left and right subtrees is greater than 1, return -1 to indicate the tree is unbalanced.
    4. Otherwise, return the actual height of the node.

Time Complexity: O(n), where n is the number of nodes in the tree, as we visit each node once.
Space Complexity: O(h), where h is the height of the tree, due to the recursion stack.
*/

class Solution {
private:
    int checkHeight(TreeNode* root) {
        if (!root) return 0;

        int left = checkHeight(root->left);
        if (left == -1) return -1;

        int right = checkHeight(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;

        return 1 + max(left, right);
    }

public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << solution.isBalanced(root) << endl; // Output: true

    return 0;
}