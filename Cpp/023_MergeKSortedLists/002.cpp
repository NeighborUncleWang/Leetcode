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
        if (0 == lists.size()) {
            return nullptr;
        }
        return divide(lists, 0, lists.size() - 1);
    }
    ListNode* divide(vector<ListNode*>& lists, int low, int high) {
        if (low < high) {
            int median = low + (high - low) / 2;
            return merge(divide(lists, low, median), divide(lists, median + 1, high));
        } else {
            return lists[low];
        }
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* sentinel = new ListNode(0);
        ListNode* iterator = sentinel;
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                iterator->next = left;
                left = left->next;
            } else {
                iterator->next = right;
                right = right->next;
            }
            iterator = iterator->next;
        }
        iterator->next = left ? left : right;
        auto result = sentinel->next;
        delete sentinel;
        return result;
    }
};
