/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
int cmp(const void*a, const void*b){
    return *(int *)a - *(int *)b;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    // 处理空输入
    if (listsSize == 0 || lists == NULL) {
        return NULL;
    }
    // 先计算总节点数
    int total = 0;
    for (int i = 0; i < listsSize; i++) {
        struct ListNode* p = lists[i];
        while (p != NULL) {
            total++;
            p = p->next;
        }
    }
    // 如果没有节点，直接返回NULL
    if (total == 0) {
        return NULL;
    }
    // 动态分配数组
    int* all_num = (int*)malloc(total * sizeof(int));
    int length = 0;
    // 收集所有节点的值
    for (int i = 0; i < listsSize; i++) {
        struct ListNode* p = lists[i];
        while (p != NULL) {  // 修复：应该用p != NULL，而不是p->next != NULL
            all_num[length++] = p->val;
            p = p->next;
        }
    }
    // 排序
    qsort(all_num, length, sizeof(int), cmp);
    // 创建结果链表
    struct ListNode* ans_head = malloc(sizeof(struct ListNode));
    struct ListNode* ans_iter = ans_head;
    ans_head->next = NULL;
    // 构建新链表
    for (int i = 0; i < length; i++) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = all_num[i];
        node->next = NULL;
        ans_iter->next = node;
        ans_iter = ans_iter->next;  // 修复：移动指针
    }
    // 释放临时数组
    free(all_num);
    struct ListNode* ans = ans_head->next;
    free(ans_head);  // 释放头节点
    return ans;
}

/*算法:
直接使用qsort排序；
时间复杂度O(n*logn)
 */