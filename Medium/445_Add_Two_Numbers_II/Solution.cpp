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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }

        return prev;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            int sum = x + y + carry;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return reverseList(dummy->next);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    ListNode* l11 = createSinglyLinkList({7,2,4,3});
    ListNode* l12 = createSinglyLinkList({5,6,4});
    ListNode* ans1 = solution.addTwoNumbers(l11, l12);
    printSinglyLinkList(ans1);

    // test cases 2
    ListNode* l21 = createSinglyLinkList({2,4,3});
    ListNode* l22 = createSinglyLinkList({5,6,4});
    ListNode* ans2 = solution.addTwoNumbers(l21, l22);
    printSinglyLinkList(ans2);

    // test cases 3
    ListNode* l31 = createSinglyLinkList({0});
    ListNode* l32 = createSinglyLinkList({0});
    ListNode* ans3 = solution.addTwoNumbers(l31, l32);
    printSinglyLinkList(ans3);

    return 0;
}