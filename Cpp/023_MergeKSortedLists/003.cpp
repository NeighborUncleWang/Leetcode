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
        if (lists.size() == 0) {
            return nullptr;
        }
        return DivideAndConquer(lists, 0, lists.size() - 1);
    }
private:
    ListNode* DivideAndConquer(vector<ListNode*>& lists, int left, int right) {
        if (left == right) {
            return lists[left];
        } else {
            int middle = left + (right - left) / 2;
            //it should be middle not middle - 1
            auto lhs = DivideAndConquer(lists, left, middle);
            auto rhs = DivideAndConquer(lists, middle + 1, right);
            ListNode temp = ListNode(-1);
            auto dummy = &temp;
            auto iterator = dummy;
            while (lhs && rhs) {
                if (lhs->val < rhs->val) {
                    iterator->next = lhs;
                    lhs = lhs->next;
                } else {
                    iterator->next = rhs;
                    rhs = rhs->next;
                }
                iterator = iterator->next;
            }
            iterator->next = lhs ? lhs : rhs;
            return dummy->next;
        }
    }
};
