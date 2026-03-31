#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Rotate List:
    1. Calculate the length of the linked list and find the last node.
    2. Connect the last node to the head to make it a circular list.
    3. The new head will be at position `(length - k % length)`.
    4. Traverse to the node just before the new head, break the circular connection by setting its next to null, and return the new head.

Time Complexity: O(n), where n is the number of nodes in the list.
Space Complexity: O(1), as we only use a few pointers.
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

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int len = 1;
        ListNode* curr = head;

        while (curr->next) {
            curr = curr->next;
            len++;
        }

        int rotate = k % len;

        if (rotate == 0) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < rotate; i++) {
            fast = fast->next;
        }

        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return newHead;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}