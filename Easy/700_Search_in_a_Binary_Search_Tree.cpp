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

Search in a Binary Search Tree:
    1. If the value is found, return the subtree rooted with that node.
    2. If the value is not found, return NULL.

Time Complexity: O(h), where h is the height of the BST. In the worst case, the tree is a line and the complexity is O(n).
Space Complexity: O(1) for the iterative approach, as we only use a pointer to traverse the tree.
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->val == val) {
                return curr;
            } else if (curr->val < val) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        return NULL;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    cout << solution.searchBST(root, 2)->val << endl; // 2
    cout << solution.searchBST(root, 5) << endl; // NULL
    
    return 0;
}