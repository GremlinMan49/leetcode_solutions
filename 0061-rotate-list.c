// 61. Rotate List (Medium)
// https://leetcode.com/problems/rotate-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    int len = 1;
    struct ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    k %= len;
    if (k == 0) return head;
    
    tail->next = head;
    struct ListNode* newTail = head;
    for (int i = 0; i < len - k - 1; i++) {
        newTail = newTail->next;
    }
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}
