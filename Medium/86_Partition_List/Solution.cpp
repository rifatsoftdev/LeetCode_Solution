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
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallDummy = new ListNode();
        ListNode* largeDummy = new ListNode();

        ListNode* small = smallDummy;
        ListNode* large = largeDummy;

        while (head != nullptr) {
            if (head->val >= x) {
                large->next = new ListNode(head->val);
                large = large->next;
            } else {
                small->next = new ListNode(head->val);
                small = small->next;
            }
            head = head->next;
        }

        small->next = largeDummy->next;

        return smallDummy->next;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    ListNode* head1 = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));
    ListNode* ans1 = solution.partition(head1, 3);
    printSinglyLinkList(ans1);  // [1,2,2,4,3,5]

    // test cases 2
    ListNode* head2 = new ListNode(2, new ListNode(1));
    ListNode* ans2 = solution.partition(head2, 2);
    printSinglyLinkList(ans2);  // [1,2]

    return 0;
}