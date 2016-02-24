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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hashSet;
        ListNode* current = head;
        while (nullptr != current) {
            if (hashSet.end() != hashSet.find(current)) {
                return current;
            } else {
                hashSet.insert(current);
            }
            current = current->next;
        }
        return nullptr;
    }
};
