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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *helper = new ListNode(0);
        ListNode *current = head;
        ListNode *predecessor = helper;
        while (current != nullptr) {
            predecessor = helper;
            while (predecessor->next != nullptr && predecessor->next->val <= current->val) {
                predecessor = predecessor->next;
            }
            ListNode *next = current->next;
            current->next = predecessor->next;
            predecessor->next = current;
            current = next;
        }
        auto result = helper->next;
        delete helper;
        return result;
    }
};
