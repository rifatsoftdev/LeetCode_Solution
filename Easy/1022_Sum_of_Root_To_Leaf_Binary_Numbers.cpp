#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
Brute Force Approach (DFS):
1. Perform a depth-first search (DFS) to find all root-to-leaf paths.
2. Convert each path from binary to decimal and sum them up.

Time Complexity: O(n) (where n is the number of nodes in the tree)
Space Complexity: O(h) (where h is the height of the tree, due to the
*/

class Solution {
public:
    int preorder(TreeNode* root, int sum) {
        if (root == NULL) return 0;

        sum = (2 * sum) + root->val;

        if (root->left == NULL && root->right == NULL) return sum;

        return preorder(root->left, sum) + preorder(root->right, sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        return preorder(root, 0);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);


    cout << solution.sumRootToLeaf(root) << endl;

    return 0;
}