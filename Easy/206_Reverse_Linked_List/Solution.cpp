#include <iostream>
#include <vector>
#include <algorithm>
#include "../../devlibs/cpp/cpphelper.h"

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

// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Reverse Linked List:
    1. Initialize three pointers: prev (initially null), current (initially head), and nextTemp (used to store the next node).
    2. Iterate through the linked list until current is null:
    a. Store the next node in nextTemp (nextTemp = current->next).
    b. Reverse the current node's pointer (current->next = prev).
    c. Move prev to the current node (prev = current).
    d. Move to the next node (current = nextTemp).
    3. At the end of the loop, prev will be the new head of the reversed linked list. Return prev.

Time Complexity: O(n), where n is the number of nodes in the linked list, since we need to traverse the entire list once.
Space Complexity: O(1), since we are using only a constant amount of extra space for the pointers.
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* nextTemp = current->next; // Store the next node
            current->next = prev; // Reverse the current node's pointer
            prev = current; // Move prev to the current node
            current = nextTemp; // Move to the next node
        }

        return prev;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    ListNode* head1 = createSinglyLinkList({1, 2, 3, 4, 5});
    ListNode* result1 = solution.reverseList(head1);
    printSinglyLinkList(result1); // Output: 5 4 3 2 1

    // test cases 2
    ListNode* head2 = createSinglyLinkList({1, 2});
    ListNode* result2 = solution.reverseList(head2);
    printSinglyLinkList(result2); // Output: 2 1

    // test cases 3
    ListNode* head3 = createSinglyLinkList({});
    ListNode* result3 = solution.reverseList(head3);
    printSinglyLinkList(result3); // Output: (empty)

    return 0;
}