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

Validate Binary Search Tree:
    1. Perform an in-order traversal of the binary tree and store the values of the nodes in a vector.
    2. After the traversal, check if the vector of values is strictly increasing (i.e., each value is less than the next value).
    3. If any adjacent values are not in strictly increasing order, return false; otherwise, return true.

Time Complexity: O(n), where n is the number of nodes in the tree, as we visit each node during traversal and then check the values.
Space Complexity: O(n) to store the values of the nodes in a vector.
*/

class Solution {
private:
    void in_order(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) return;

        in_order(root->left, nums);
        nums.push_back(root->val);
        in_order(root->right, nums);
    }

public:
    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        in_order(root, nums);

        if (nums.size() <= 1) return true;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] >= nums[i+1]) return false;
        }

        return true;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}