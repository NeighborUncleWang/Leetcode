/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* iter = head;
        while (iter) {
            RandomListNode* next = iter->next;
            iter->next = new RandomListNode(iter->label);
            iter->next->next = next;
            iter = next;
        }
        iter = head;
        while (iter) {
            //remember to rest whether oldList->random != nullptr
            if (iter->random != nullptr) {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        iter = head;
        RandomListNode dummyNode(0);
        RandomListNode* dummy = &dummyNode;
        RandomListNode* iterNew = dummy;
        while (iter) {
            RandomListNode* next = iter->next->next;
            iterNew->next = iter->next;
            iter->next = next;
            iter = iter->next;
            iterNew = iterNew->next;
        }
        return dummy->next;
    }
};