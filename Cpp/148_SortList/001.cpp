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
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        //这里不要用fast && fast->next作为while loop的判断条件
        //否则当输入list长度为2时
        //最后fast = nullptr
        //slow->next = nullptr
        //等于说slow指向最后一个元素
        //就相当于没有做split，后面l1的size一直是2
        //l2的size一直是0
        //l1的永远达不到head == nullptr || head->next == nullptr的递归退出条件
        //程序最后陷入死循环
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto next = slow->next;
        slow->next = nullptr;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(next);
        //merge l1 and l2
        ListNode dummyNode(0);
        ListNode* dummy = &dummyNode;
        auto iter = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                iter->next = l1;
                l1 = l1->next;
            } else {
                iter->next = l2;
                l2 = l2->next;
            }
            iter = iter->next;
        }
        iter->next = l1 ? l1 : l2;
        return dummy->next;
    }
};