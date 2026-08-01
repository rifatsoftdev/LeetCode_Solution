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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head;
        ListNode* newHead = new ListNode(0);
        ListNode* newCurr = newHead;

        int sum = 0;

        while (curr) {
            if (curr->val == 0) {
                if (sum > 0) {
                    newCurr->next = new ListNode(sum);
                    newCurr = newCurr->next;
                    sum = 0;
                }
            } else {
                sum += curr->val;
            }
            
            curr = curr->next;
        }

        return newHead->next;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    ListNode* head1 = createSinglyLinkList({0,3,1,0,4,5,2,0});
    ListNode* result1 = solution.mergeNodes(head1);
    printSinglyLinkList(result1); // Expected output: 4 -> 11

    // test cases 2
    ListNode* head2 = createSinglyLinkList({0,1,0,3,0,2,2,0});
    ListNode* result2 = solution.mergeNodes(head2);
    printSinglyLinkList(result2); // Expected output: 1 -> 3 -> 4

    return 0;
}