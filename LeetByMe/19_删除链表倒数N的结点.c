/**
 * Definition for singly-linked list.
**/
#include<stdio.h>

struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* node_iter = head;
    int length = 0;
    while(node_iter!= NULL){
        node_iter = node_iter->next;
        length ++;
    }
    node_iter = head;
    if(length == n){
        struct ListNode * node_ans = head->next;
        return node_ans;    
    }
    for(int i = 0;i<length - n - 1;i++){
        node_iter = node_iter->next;
    }
    struct ListNode * node_del = node_iter->next;
    node_iter->next = node_del->next;
    return head;
}