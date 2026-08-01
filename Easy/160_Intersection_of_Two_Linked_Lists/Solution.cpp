#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        for (ListNode *tmp = headA; tmp != NULL; tmp = tmp->next) {
            for (ListNode *tmpB = headB; tmpB != NULL; tmpB = tmpB->next) {
                if (tmp == tmpB) {
                    return tmp;
                }
            }
        }

        return NULL;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    // test cases 2

    return 0;
}