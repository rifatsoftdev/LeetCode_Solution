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
Middle of the Linked List:
1. Initialize two pointers, `slow` and `fast`, to the head of the linked list.
2. Move the `fast` pointer two steps at a time and the `slow` pointer one step at a time.
3. When the `fast` pointer reaches the end of the linked list (i.e., `fast` is null or `fast->next` is null), the `slow` pointer will be at the middle node of the linked list.
4. Return the `slow` pointer as the middle node of the linked list.

Time Complexity: O(n), where n is the number of nodes in the linked list. We traverse the linked list at most once.
Space Complexity: O(1), as we are using only a constant amount of extra space for the two pointers.
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* middle1 = solution.middleNode(head1);
    printLinkList(middle1);

    ListNode* head2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
    ListNode* middle2 = solution.middleNode(head2);
    printLinkList(middle2);

    return 0;
}