#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Remove Nth Node From End of List:
1. Calculate the length of the linked list.
2. Determine the position of the node to be removed from the start of the list using the formula: deleteNode = length - n + 1.
3. If the node to be removed is the head (deleteNode == 1), update the head to the next node and delete the original head.
4. Otherwise, traverse the list to find the node just before the one to be removed (deleteNode - 1) and update its next pointer to skip the node to be removed.
5. Delete the node to be removed and return the head of the modified list.

Time Complexity: O(L), where L is the length of the linked list, since we need to traverse the list to calculate its length and to find the node to be removed.
Space Complexity: O(1), since we are using only a constant amount of extra space for pointers and variables.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* current = head;

        while (current != nullptr) {
            length++;
            current = current->next;
        }

        int deleteNode = length - n + 1;
        if (deleteNode == 1) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        current = head;
        for (int i = 1; i < deleteNode - 1; i++) {
            current = current->next;
        }

        ListNode* nodeToRemove = current->next;
        current->next = current->next->next;
        delete nodeToRemove;
        return head;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    head1 = solution.removeNthFromEnd(head1, 2);
    printLinkList(head1);

    return 0;
}