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
    ListNode* deleteMiddle(ListNode* head) {
        // edge case
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = prev->next->next;

        return head;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    ListNode* head1 = createSinglyLinkList({1, 3, 4, 7, 1, 2, 6});
    ListNode* result1 = solution.deleteMiddle(head1);
    printSinglyLinkList(result1);
    
    // test cases 2
    ListNode* head2 = createSinglyLinkList({1,2,3,4});
    ListNode* result2 = solution.deleteMiddle(head2);
    printSinglyLinkList(result2);

    // test cases 3
    ListNode* head3 = createSinglyLinkList({2,1});
    ListNode* result3 = solution.deleteMiddle(head3);
    printSinglyLinkList(result3);

    return 0;
}