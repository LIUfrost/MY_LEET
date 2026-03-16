// 前置知识：翻转整个链表
/*
 while (cur) {
     nxt = cur->next;
     cur->next = pre;
     pre = cur;
     cur = nxt;
}
*/

#include<stdio.h>
struct ListNode {
   int val;
   struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    // 统计节点个数
    int n = 0;
    for (struct ListNode* cur = head; cur; cur = cur->next) {
        n++;
    }

    struct ListNode dummy = {0, head};
    struct ListNode* p0 = &dummy;
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;

    // k 个一组处理
    for (; n >= k; n -= k) {
        for (int i = 0; i < k; i++) { // 同 92 题
            struct ListNode* nxt = cur->next;
            cur->next = pre; // 每次循环只修改一个 next，方便大家理解
            pre = cur;
            cur = nxt;
        }

        // 见视频
        struct ListNode* nxt = p0->next;
        p0->next->next = cur;
        p0->next = pre;
        p0 = nxt;
    }
    return dummy.next;
}
/*算法：
例如：1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7，k = 3;

初始状态：
dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
p0指向dummy
pre = NULL
cur = 1
n = 7

处理第一组
    反转过程：
    第1步: 1->NULL, pre=1, cur=2
    第2步: 2->1->NULL, pre=2, cur=3  
    第3步: 3->2->1->NULL, pre=3, cur=4

    连接操作：
    nxt = p0->next;           // nxt保存节点1（原第一个节点）
    p0->next->next = cur;     // 节点1（现最后一个）指向cur(4)
    p0->next = pre;           // dummy指向pre(3)
    p0 = nxt;                 // p0指向节点1
*/