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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return head;
        int length = 0;
        auto iter = head;
        while (iter) {
            iter = iter->next;
            ++length;
        }
        return mergeSort(head, length);
    }
private:
    ListNode* mergeSort(ListNode*& head, int length) {
        if (length == 1) {
            auto temp = head;
            head = head->next;
            temp->next = nullptr;
            return temp;
        }
        auto leftHead = mergeSort(head, length / 2);
        auto rightHead = mergeSort(head, length - length / 2);
        ListNode dummyNode(0);
        ListNode* dummy = &dummyNode;
        auto iter = dummy;
        while (leftHead && rightHead) {
            if (leftHead->val < rightHead->val) {
                iter->next = leftHead;
                leftHead = leftHead->next;
            } else {
                iter->next = rightHead;
                rightHead = rightHead->next;
            }
            iter = iter->next;
        }
        iter->next = leftHead ? leftHead : rightHead;
        return dummy->next;
    }
};