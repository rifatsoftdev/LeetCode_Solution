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
    void reorderList(ListNode* head) {
        vector<int> arr;

        ListNode* curr = head;

        while (curr != nullptr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }

        int n = arr.size() - 1;
        int cnt = 0;
        curr = head;

        while (cnt <= n) {
            if (cnt % 2 == 0) {
                curr->val = arr[cnt / 2];
            } else {
                curr->val = arr[n - (cnt / 2)];
            }
            curr = curr->next;
            cnt++;
        }
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> list1 = {1, 2, 3, 4};
    ListNode* head1 = createSinglyLinkList(list1);
    solution.reorderList(head1);
    printSinglyLinkList(head1);
    
    // test cases 2
    vector<int> list2 = {1, 2, 3, 4, 5};
    ListNode* head2 = createSinglyLinkList(list2);
    solution.reorderList(head2);
    printSinglyLinkList(head2);

    return 0;
}