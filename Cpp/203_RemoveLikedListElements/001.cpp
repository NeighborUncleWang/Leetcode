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
    //assume the linkedlist is on the heap
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* headNode = new ListNode(0);
        headNode->next = head;
        ListNode* temp = headNode;
        while (nullptr != temp->next) {
            if (val == temp->next->val) {
                auto p = temp->next;
                temp->next = temp->next->next;
                delete p;
            } else {
                temp = temp->next;
            }
        }
        auto result = headNode->next;
        delete headNode;
        return result;//do we need to consider the memory leakage during interview?
    }
};
