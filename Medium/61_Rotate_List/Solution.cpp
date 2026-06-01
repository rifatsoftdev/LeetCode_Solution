#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


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
    
    // test cases 1
    ListNode* head1 = createSinglyLinkList({1,2,3,4,5});
    int k1 = 2;
    ListNode* result1 = solution.rotateRight(head1, k1);
    printSinglyLinkList(result1); // Expected output: 4 -> 5 -> 1 -> 2 -> 3

    // test cases 1
    ListNode* head2 = createSinglyLinkList({0,1,2});
    int k2 = 4;
    ListNode* result2 = solution.rotateRight(head2, k2);
    printSinglyLinkList(result2); // Expected output: 2 -> 0 -> 1

    return 0;
}