/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdio.h>

struct ListNode {
   int val;
   struct ListNode *next;
};
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *ans_head = malloc(sizeof(struct ListNode));
    ans_head->next = head;
    struct ListNode *ans_iter = ans_head;
    while (ans_iter != NULL && ans_iter->next != NULL){
        struct ListNode *ans_next = ans_iter->next;
        struct ListNode *next_next = ans_next->next;
        if(next_next == NULL)    break;
        ans_next->next = next_next->next;
        next_next->next = ans_next;
        ans_iter->next = next_next;
        ans_iter = ans_next;
    }
    struct ListNode *ans = ans_head->next;
    free(ans_head);
    return ans;
}