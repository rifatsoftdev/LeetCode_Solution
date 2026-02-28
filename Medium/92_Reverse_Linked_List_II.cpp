#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


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

/*
Reverse Linked List II:
1. Create a dummy node and point its next to the head of the list. This helps in handling edge cases where the head might be reversed.
2. Use a pointer (prev) to traverse the list until it reaches the node just before the left position (left - 1).
3. Use another pointer (curr) to point to the left position (the start of the sublist to be reversed).
4. Reverse the sublist from left to right using a loop:
   a. In each iteration, store the next node (temp) of curr.
   b. Update the next pointer of curr to skip temp (curr->next = temp->next).
   c. Insert temp at the beginning of the reversed sublist (temp->next = prev->next; prev->next = temp).
5. After the loop, the sublist will be reversed, and the dummy node's next will point to the new head of the list. Return dummy.next.
Time Complexity: O(n), where n is the number of nodes in the linked list, since we need to traverse the list at most twice (once to reach left and once to reverse the sublist).

Space Complexity: O(1), since we are using only a constant amount of extra space for the pointers.
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        // Step 1: go to (left - 1)
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        // Step 2: reverse sublist
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy.next;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int left1 = 2, right1 = 4;
    ListNode* result1 = solution.reverseBetween(head1, left1, right1);
    printLinkList(result1); // Expected output: 1 -> 4 -> 3 -> 2 -> 5

    ListNode* head2 = new ListNode(5);
    int left2 = 1, right2 = 1;
    ListNode* result2 = solution.reverseBetween(head2, left2, right2);
    printLinkList(result2); // Expected output: 5

    return 0;
}