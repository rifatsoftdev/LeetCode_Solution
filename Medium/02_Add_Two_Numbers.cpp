#include <iostream>
#include "../devlibs/cpphelper.h"

using namespace std;


// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };


/*
Brute Force Approach:
1. Initialize a dummy head for the result linked list and a current pointer to track the last node in the result list.
2. Initialize a carry variable to 0.
3. Loop through both linked lists until you reach the end of both lists and there is no carry:
   a. Get the values from the current nodes of both lists (or 0 if the list has been fully traversed).
   b. Calculate the sum of the two values and the carry.
   c. Update the carry for the next iteration (carry = sum / 10).
   d. Create a new node with the value of (sum % 10) and set it as the next node of the current pointer.
   e. Move the current pointer to the next node.
   f. Move to the next nodes in both linked lists if they exist.
4. Return the next node of the dummy head, which is the head of the resulting linked list.

Time Complexity: O(max(m, n)) where m and n are the lengths of the two linked lists.
Space Complexity: O(max(m, n)) for the resulting linked list.
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); // dummy head
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

        return dummy->next; // skip dummy node
    }
};


int main() {
    Solution solution;

    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3, nullptr)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4, nullptr)));

    ListNode* ans = solution.addTwoNumbers(l1, l2);

    printLinkList(ans);


    return 0;
}