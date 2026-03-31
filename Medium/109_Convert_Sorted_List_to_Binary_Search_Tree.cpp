#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Convert Sorted List to Binary Search Tree:
    1. First, we need to convert the sorted linked list into an array to facilitate easy access to the middle element.
    2. Then, we can use the same approach as in the "Convert Sorted Array to Binary Search Tree" problem:
        a. The middle element of the array will be the root of the BST.
        b. Recursively build the left subtree using the left half of the array.
        c. Recursively build the right subtree using the right half of the array.
    3. The base case for recursion is when the left index exceeds the right index, at which point we return null.

Time Complexity: O(n), where n is the number of nodes in the linked list, as we need to traverse the list to create the array and then build the BST.
Space Complexity: O(n) for the array to store the linked list values, and O(log n) for the recursion stack when building the BST, resulting in O(n) overall due to the array storage.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    TreeNode* buildBST(const vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        node->left = buildBST(nums, left, mid - 1);
        node->right = buildBST(nums, mid + 1, right);
        
        return node;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        ListNode* temp = head;

        while (temp != nullptr) {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        return buildBST(nums, 0, nums.size() - 1);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}