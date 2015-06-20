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
    struct comparator {
        bool operator()(ListNode*& lhs, ListNode*& rhs) {
            return lhs->val > rhs->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> temp = lists;
        ListNode* sentinel = new ListNode(0);
        ListNode* iterator = sentinel;
        priority_queue<ListNode*, vector<ListNode*>, comparator> heap;
        for (auto it : lists) {
            if (nullptr != it) {
                heap.push(it);
            }
        }
        while (heap.empty() != true) {
            ListNode* current = heap.top();
            iterator->next = current;
            iterator = iterator->next;
            heap.pop();
            if (nullptr != current->next) {
                heap.push(current->next);
            }
        }
        ListNode* result = sentinel->next;
        delete sentinel;
        return result;
    }
};
