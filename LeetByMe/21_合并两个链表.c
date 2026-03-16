/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode* head_iter = head;
    struct ListNode* l1_iter = list1, * l2_iter = list2;
    while(l1_iter || l2_iter){
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->next = NULL;
        
        if(l1_iter == NULL){
            node->val = l2_iter->val;
            l2_iter = l2_iter->next;        
        }
        else if(l2_iter == NULL){
            node->val = l1_iter->val;
            l1_iter = l1_iter->next;        
        }
        else if(l1_iter->val < l2_iter->val){
            node->val = l1_iter->val;
            l1_iter = l1_iter->next;
        }
        else{
            node->val = l2_iter->val;
            l2_iter = l2_iter->next;
        }
        head_iter->next = node;
        head_iter = head_iter->next;
    }
    struct ListNode * ans = head->next;
    return ans;
}