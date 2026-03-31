#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Flatten Binary Tree to Linked List:
    1. Perform a pre-order traversal of the binary tree and store all nodes in a vector.
    2. Iterate through the stored nodes and for each node, set its left child to null and its right child to the next node in the vector.
    3. For the last node in the vector, set both its left and right children to null.
    4. This effectively flattens the tree into a linked list in-place using the pre-order sequence.

Time Complexity: O(n), where n is the number of nodes in the tree, as we visit each node during traversal and then again to relink.
Space Complexity: O(n) to store the nodes in a vector.
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
    void pre_order(TreeNode* root, vector<TreeNode*>& nodes) {
        if (root == nullptr) return;

        nodes.push_back(root);

        pre_order(root->left, nodes);
        pre_order(root->right, nodes);
    }

public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        vector<TreeNode*> nodes;
        pre_order(root, nodes);

        for (int i = 0; i < nodes.size() - 1; i++) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }

        // last node
        nodes.back()->left = nullptr;
        nodes.back()->right = nullptr;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}