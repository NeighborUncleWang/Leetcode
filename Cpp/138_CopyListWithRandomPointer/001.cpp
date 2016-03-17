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
        unordered_map<RandomListNode*, RandomListNode*> hashMap;
        RandomListNode dummyNode(0);
        RandomListNode* dummy = &dummyNode;
        RandomListNode* iterNew = dummy;
        RandomListNode* iterOriginal = head;
        while (iterOriginal) {
            iterNew->next = new RandomListNode(iterOriginal->label);
            hashMap[iterOriginal] = iterNew->next;
            iterNew = iterNew->next;
            iterOriginal = iterOriginal->next;
        }
        iterNew = dummy->next;
        iterOriginal = head;
        while (iterOriginal) {
            iterNew->random = hashMap[iterOriginal->random];
            iterNew = iterNew->next;
            iterOriginal = iterOriginal->next;
        }
        return dummy->next;
    }
};