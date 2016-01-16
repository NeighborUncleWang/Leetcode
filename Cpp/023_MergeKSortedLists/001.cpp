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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //or we can use decltype to get the type of lambda
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> 
        heap([](ListNode* lhs, ListNode* rhs) -> bool {
            return rhs->val < lhs->val;
        });
        ListNode temp(-1);
        ListNode* dummy = &temp;
        ListNode* iterator = dummy;
        for (ListNode* list : lists) {
            if (list != nullptr) {
                heap.push(list);
            }
        }
        while (!heap.empty()) {
            ListNode* current = heap.top();
            iterator->next = current;
            iterator = iterator->next;
            heap.pop();
            if (current->next != nullptr) {
                heap.push(current->next);
            }
        }
        return dummy->next;
    }
};