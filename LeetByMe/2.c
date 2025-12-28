#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    long num1 = 0, num2 = 0,i = 1;
    while(p1 != NULL){
        num1 += p1->val * i;
        i *= 10;
        p1 = p1->next;
    }
    i = 1;
    while(p2 != NULL){
        num2 += p2->val * i;
        i *= 10;
        p2 = p2->next;
    }
    long num3 = num1 + num2;
    struct ListNode *p3 = malloc(sizeof(struct ListNode));
    p3->val = 0;
    p3->next = NULL;
    struct ListNode *tail = p3;
    while(num3 != 0){
        struct ListNode *NODE = malloc(sizeof(struct ListNode));
        NODE->val = num3 % 10;
        NODE->next = NULL;
        num3 = num3 / 10;
        tail->next = NODE;
        tail = tail->next;
    }
    struct ListNode *answer = p3->next;
    free(p3);
    if (answer == NULL) {
        answer = malloc(sizeof(struct ListNode));
        answer->val = 0;
        answer->next = NULL;
    }
    return answer;
}

//def客户端

void printList(struct ListNode *head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct ListNode *l1 = malloc(sizeof(struct ListNode));
    struct ListNode *l2 = malloc(sizeof(struct ListNode));
    struct ListNode *l3 = malloc(sizeof(struct ListNode));
    l1->val = 3;
    l1->next = l3;
    l3->val = 5;
    l3->next = NULL;
    l2->val = 5;
    l2->next = NULL;
    struct ListNode *result = addTwoNumbers(l1, l2);
    printList(result);
    
    return 0;
}