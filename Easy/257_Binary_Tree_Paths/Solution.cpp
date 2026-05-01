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

Binary Tree Paths:
    1. Use a recursive approach to traverse the binary tree.
    2. If the current node is a leaf (no left or right child), return its value as a string.
    3. If the current node is not a leaf, recursively find the paths for its left and right subtrees.
    4. For each path returned from the subtrees, prepend the current node's value followed by "->".
    5. Return the combined list of paths.

Time Complexity: O(n), where n is the number of nodes in the tree, as we visit each node once.
Space Complexity: O(h), where h is the height of the tree, due to the recursion stack.
*/

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == nullptr) {
            return result;
        }

        if (root->left == nullptr && root->right == nullptr) {
            result.push_back(to_string(root->val));
            return result;
        }

        vector<string> leftPaths = binaryTreePaths(root->left);
        vector<string> rightPaths = binaryTreePaths(root->right);

        for (const string& path : leftPaths) {
            result.push_back(to_string(root->val) + "->" + path);
        }

        for (const string& path : rightPaths) {
            result.push_back(to_string(root->val) + "->" + path);
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->right = new TreeNode(5);

    vector<string> result1 = solution.binaryTreePaths(root1);
    printVec(result1);


    return 0;
}