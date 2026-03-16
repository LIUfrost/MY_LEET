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
// node1和node1->next之间的互换
void Node_reverse(struct ListNode** node1){
    struct ListNode *NODE1 = (*node1);
    struct ListNode *NODE2 = NODE1->next;
    NODE1->next = NODE2->next;
    NODE2->next = NODE1;
    *node1 = NODE2;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *check = head;
    for (int i = 0; i < k;i++){
        if(check == NULL) {
            return head;
        }
        check = check->next;
    }
    struct ListNode *current = head;
    for (int i = k - 1; i > 0; i--)
    {
        struct ListNode **temp = &current;
        for (int j = 0; j < i; j++)
        {
            Node_reverse(temp);
            temp = &((*temp)->next);
        }
    }
    head->next = reverseKGroup(check, k);
    return current;
}
/*算法：
时间复杂度O(n*k)
差！
*/