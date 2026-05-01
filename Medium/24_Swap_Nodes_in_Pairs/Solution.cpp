#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Swap Nodes in Pairs (Iterative Value Swap):
    1. Traverse the linked list using a pointer `temp`, starting from the `head`.
    2. In each step, check if the current node and the next node exist.
    3. If both exist, swap their values.
    4. Move the pointer `temp` two steps forward to the next pair.
    5. Continue until the end of the list is reached.

Time Complexity: O(n), where n is the number of nodes in the linked list.
Space Complexity: O(1), as we only swap values in-place without using extra nodes.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;

        while (temp != nullptr && temp->next != nullptr) {
            swap(temp->val, temp->next->val);
            temp = temp->next->next;
        }

        return head;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    ListNode* result1 = solution.swapPairs(head1);
    printSinglyLinkList(result1); // Expected output: 2 -> 1 -> 4

    ListNode* head2 = new ListNode();
    ListNode* result2 = solution.swapPairs(head2);
    printSinglyLinkList(result2); // Expected output: (empty)

    ListNode* head3 = new ListNode(1);
    ListNode* result3 = solution.swapPairs(head3);
    printSinglyLinkList(result3); // Expected output: 1

    ListNode* head4 = new ListNode(1, new ListNode(2, new ListNode(3)));
    ListNode* result4 = solution.swapPairs(head4);
    printSinglyLinkList(result4); // Expected output: 2 -> 1 -> 3

    return 0;
}