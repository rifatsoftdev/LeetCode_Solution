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
Optimal Solution (Insertion Sort):
1. We can use the insertion sort algorithm to sort the linked list in-place.
2. We create a dummy node that will serve as the new head of the sorted list.
3. We iterate through the original list and for each node, we find the correct position in the sorted list and insert it there.
4. We maintain a pointer to the current node in the original list and a pointer to the last node in the sorted list to optimize the insertion process.

Space Complexity: O(1)
Time Complexity: O(n^2)
*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            ListNode* prevNode = &dummy;

            while (prevNode->next != nullptr && prevNode->next->val < curr->val) {
                prevNode = prevNode->next;
            }

            curr->next = prevNode->next;
            prevNode->next = curr;
            curr = nextNode;
        }
        
        return dummy.next;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    ListNode* head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    head = solution.insertionSortList(head);
    printLinkList(head); // Output: 1 -> 2 -> 3 -> 4

    return 0;
}