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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    ListNode* head1 = createSinglyLinkList({1, 2, 3, 4, 5});
    ListNode* result1 = solution.oddEvenList(head1);
    printSinglyLinkList(result1); // Expected output: 1 -> 3 -> 5 -> 2 -> 4

    // test cases 2
    ListNode* head2 = createSinglyLinkList({2, 1, 3, 5, 6, 4, 7});
    ListNode* result2 = solution.oddEvenList(head2);
    printSinglyLinkList(result2); // Expected output: 2 -> 3 -> 6 -> 7 -> 1 -> 5 -> 4

    return 0;
}