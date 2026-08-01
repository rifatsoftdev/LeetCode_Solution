#include "../../devlibs/cpp/cpphelper.h"

using namespace std;



// Definition for singly-linked list.
// struct ListNode {
// int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
// };



// NOTE:
// For LeetCode submission, copy only the `class Solution` part.

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
    
    // test cases 1
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
    ListNode* result1 = solution.removeElements(head1, 6);
    printSinglyLinkList(result1);

    // test cases 2
    ListNode* head2 = new ListNode();
    ListNode* result2 = solution.removeElements(head2, 1);
    printSinglyLinkList(result2);

    // test cases 3
    ListNode* head3 = new ListNode(7, new ListNode(7, new ListNode(7, new ListNode(7))));
    ListNode* result3 = solution.removeElements(head3, 7);
    printSinglyLinkList(result3);

    return 0;
}