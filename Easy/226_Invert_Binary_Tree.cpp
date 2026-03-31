#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Invert Binary Tree:
    1. To invert a binary tree, we need to swap the left and right children of every node in the tree.
    2. This can be achieved using a recursive approach (Depth-First Search).
    3. For the current node, swap its `left` and `right` pointers.
    4. Recursively call the invert function on the left child and the right child.
    5. The base case for the recursion is when the current node is `nullptr`.

Time Complexity: O(n), where n is the number of nodes in the tree, as we visit each node once.
Space Complexity: O(h), where h is the height of the tree, due to the recursive call stack.
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
    void invert(TreeNode* root) {
        if (root == nullptr) return;
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        invert(root->left);
        invert(root->right);
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    

    return 0;
}