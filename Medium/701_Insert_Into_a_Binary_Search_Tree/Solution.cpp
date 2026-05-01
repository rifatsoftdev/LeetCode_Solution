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

Insert into a Binary Search Tree:
    1. If the tree is empty, return a new node with the given value.
    2. Otherwise, compare the given value with the value of the current node:
    a. If the given value is less than the current node's value, recursively insert the value into the left subtree.
    b. If the given value is greater than the current node's value, recursively insert the value into the right subtree.
    3. Return the unchanged node pointer (the root of the tree).

Time Complexity: O(h), where h is the height of the tree. In the worst case (when the tree is skewed), this can be O(n), where n is the number of nodes in the tree. In the average case (when the tree is balanced), this is O(log n).
Space Complexity: O(h) due to the recursive call stack. In the worst case (when the tree is skewed), this can be O(n). In the average case (when the tree is balanced), this is O(log n).
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);

        if (root == NULL) return newNode;

        TreeNode* curr = root;

        while (curr != NULL) {
            if (val < curr->val) {
                if (curr->left != NULL) {
                    curr =  curr->left;
                } else {
                    curr->left = newNode;
                    break;
                }
            } else {
                if (curr->right != NULL) {
                    curr =  curr->right;
                } else {
                    curr->right = newNode;
                    break;
                }
            }
        }
        
        return root;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}