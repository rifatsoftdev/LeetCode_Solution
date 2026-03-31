#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Increasing Order Search Tree:
    1. Perform an inorder traversal of the given Binary Search Tree to collect all node values in a sorted list.
    2. Create a new tree by iterating through the sorted list.
    3. For each value, create a new node and attach it as the right child of the previous node, ensuring all left pointers are null.
    4. Return the head of the newly created skewed tree.

Time Complexity: O(n), where n is the number of nodes in the tree, as we visit each node during traversal and again when building the new tree.
Space Complexity: O(n) to store the node values in a vector and for the recursion stack.
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
    void inorder(TreeNode* root, vector<int> &ans) {
        if (root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);

        TreeNode* head = new TreeNode(ans[0]);
        TreeNode* curr = head;

        for (int i = 1; i < ans.size(); i++) {
            curr->right = new TreeNode(ans[i]);
            curr = curr->right;
        }

        return head;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}