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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode * curr = head;

        while (curr != nullptr) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        return prev;
    }

public:
    int pairSum(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow = reverseList(slow->next);
        fast = head;

        int result = 0;

        while (fast != nullptr && slow != nullptr) {
            result = max(result, fast->val+slow->val);
            fast = fast->next;
            slow = slow->next;
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    ListNode *head1 = createSinglyLinkList({5,4,2,1});
    cout << solution.pairSum(head1) << endl;

    // test cases 2
    ListNode *head2 = createSinglyLinkList({4,2,2,3});
    cout << solution.pairSum(head2) << endl;

    // test cases 3
    ListNode *head3 = createSinglyLinkList({1,100000});
    cout << solution.pairSum(head3) << endl;    

    return 0;
}