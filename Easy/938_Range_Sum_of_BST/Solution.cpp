#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

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


/* ================================================================================
Solution 1:

Range Sum of BST:
    1. Perform an inorder traversal of the Binary Search Tree.
    2. For each node, check if its value lies within the inclusive range [low, high].
    3. If the value is within the range, add it to the running sum.
    4. Return the total sum after traversing the tree.

Time Complexity: O(n), where n is the number of nodes in the tree, as we visit each node once.
Space Complexity: O(h), where h is the height of the tree, due to the recursive call stack.
*/

class Solution {
private:
    void inorder(TreeNode* root, long long &ans, int low, int high) {
        if (root == NULL) return;
        
        inorder(root->left, ans, low, high);
        if (root->val >= low && root->val <= high) ans += root->val;
        inorder(root->right, ans, low, high);
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        long long ans = 0;
        inorder(root, ans, low, high);
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}