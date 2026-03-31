#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Kth Smallest Element in a BST:
    1. Perform an inorder traversal of the Binary Search Tree.
    2. Since an inorder traversal of a BST visits nodes in non-decreasing order, store the values in a vector.
    3. The k-th smallest element will be at index `k-1` in the resulting sorted vector.

Time Complexity: O(n), where n is the number of nodes in the tree.
Space Complexity: O(n) to store the elements in a vector.
*/

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
    void inorder(TreeNode* root, vector<int>& arr) {
        if (root == NULL) return;

        inorder(root->left, arr);   // left
        arr.push_back(root->val);   // root
        inorder(root->right, arr);  // right
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);
        return arr[k-1];
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}