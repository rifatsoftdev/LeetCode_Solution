#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/**
// Definition for singly-linked list.
struct ListNode {
int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/


/*
Brute Force Approach:
1. Traverse the linked list and for each node, check if its value is equal to the target value.
2. If it is, remove the node from the linked list by updating the next pointer of the previous node to skip the current node.
3. Continue this process until the end of the linked list is reached.

Time Complexity: O(n), where n is the number of nodes in the linked list.
Space Complexity: O(1), as we are modifying the linked list in place without using any additional data structures.
*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* current = dummy;
        
        while (current->next != NULL) {
            if (current->next->val == val) {
                ListNode* temp = current->next;
                current->next = temp->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
        
        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
    ListNode* result1 = solution.removeElements(head1, 6);
    printLinkList(result1);

    ListNode* head2 = new ListNode();
    ListNode* result2 = solution.removeElements(head2, 1);
    printLinkList(result2);

    ListNode* head3 = new ListNode(7, new ListNode(7, new ListNode(7, new ListNode(7))));
    ListNode* result3 = solution.removeElements(head3, 7);
    printLinkList(result3);

    return 0;
}