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
        if (lists.empty()) {
            return nullptr;
        }
        return SplitMerge(lists, 0, lists.size());
    }
private:
    ListNode* SplitMerge(vector<ListNode*>& lists, int start, int end) {
        if (end - start < 2) {
            return lists[start];
        }
        int middle = start + (end - start) / 2;
        ListNode* left = SplitMerge(lists, start, middle);
        ListNode* right = SplitMerge(lists, middle, end);
        ListNode temp(-1);
        ListNode* dummy = &temp;
        ListNode* iterator = dummy;
        //也可以写成 while (left || right) {
            //if (left && (!right || left->val < right->val))
        //}
        //这样最后就不用写iterator->next = left == nullptr ? right : left;
        //这个是wikipedia上merge的写法
        while (left && right) {
            if (left->val < right->val) {
                iterator->next = left;
                left = left->next;
            } else {
                iterator->next = right;
                right = right->next;
            }
            iterator = iterator->next;
        }
        iterator->next = left == nullptr ? right : left;
        return dummy->next;
    }
};