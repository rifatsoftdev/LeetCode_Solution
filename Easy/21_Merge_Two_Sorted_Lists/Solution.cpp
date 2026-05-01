#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Merge Two Sorted Lists:
    1. Create a dummy node to serve as the starting point of the merged list.
    2. Use a pointer `current` to keep track of the last node in the merged list.
    3. Compare the values of the nodes at the head of both input lists.
    4. Append the node with the smaller value to the merged list and move the pointer in that list forward.
    5. Repeat this process until one of the lists is exhausted.
    6. If any nodes remain in either list, append them to the end of the merged list.
    7. Return the next node of the dummy node as the head of the merged list.

Time Complexity: O(n + m), where n and m are the lengths of the two linked lists.
Space Complexity: O(1), as we are rearranging the existing nodes and only using a constant amount of extra space for pointers.
*/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        ListNode* sort_head = new ListNode();
        ListNode* current = sort_head;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if (list1) current->next = list1;
        if (list2) current->next = list2;

        return sort_head->next;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* result1 = solution.mergeTwoLists(list1, list2);
    printSinglyLinkList(result1);

    ListNode* list3 = new ListNode();
    ListNode* list4 = new ListNode();
    ListNode* result2 = solution.mergeTwoLists(list3, list4);
    printSinglyLinkList(result2);

    ListNode* list5 = new ListNode();
    ListNode* list6 = new ListNode(0);
    ListNode* result3 = solution.mergeTwoLists(list5, list6);
    printSinglyLinkList(result3);

    return 0;
}