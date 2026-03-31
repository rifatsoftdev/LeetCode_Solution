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

Level Order Traversal of a Binary Tree:
    1. Use a queue to perform a breadth-first traversal of the tree.
    2. For each level, determine the number of nodes at that level (using the size of the queue).
    3. Process each node at the current level, adding their values to a temporary vector and enqueueing their children for the next level.
    4. After processing all nodes at the current level, add the temporary vector to the final answer vector.
    5. Continue until the queue is empty, which means all levels have been processed.

Time Complexity: O(n), where n is the number of nodes in the tree, since we visit each node exactly once.
Space Complexity: O(n), in the worst case (when the tree is completely unbalanced), the queue can hold all nodes at the last level, which can be up to n/2 nodes.
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back({root->val});

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;

            while (sz--) {
                TreeNode* f = q.front();
                q.pop();

                if (f->left != NULL) {
                    q.push(f->left);
                    level.push_back(f->left->val);
                }

                if (f->right != NULL) {
                    q.push(f->right);
                    level.push_back(f->right->val);
                }
            }
            if (level.size() > 0) ans.push_back(level);
        }
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = solution.levelOrder(root);
    printVec2D(ans);

    return 0;
}