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
int numsSize;  // 当前堆的大小
// 二进制堆下沉操作(O(logn))
void sink(struct ListNode** nums, int i){
    int child;
    struct ListNode* tmp = nums[i];
    while(i * 2 <= numsSize){
        child = i * 2;  // 左孩子下标
        if(child + 1 <= numsSize && nums[child+1]->val < nums[child]->val)
            child++;  // 如果有右孩子且右孩子更小，则选右孩子
        if(nums[child]->val >= tmp->val)
            break;  // 如果当前节点已经比两个孩子都小了，则调整结束
        nums[i] = nums[child]; // 否则将较小的孩子上移
        i = child; // 继续向下调整
    }
    nums[i] = tmp;  // 将原节点放在最终位置
}
void CreateHeap(struct ListNode** nums){
    int i;
    struct ListNode* tmp;
    for(i = numsSize / 2; i >= 1; i--){   // 从最后一个非叶子节点开始向下调整
        sink(nums, i);
    }
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* head =  (struct ListNode*)calloc(1, sizeof(struct ListNode)), *tail = head;
    struct ListNode** nums = (struct ListNode**)calloc(listsSize + 1, sizeof(struct ListNode*));
    int i;
    numsSize = 0;
    for(i = 1; i <= listsSize; i++){
        if(lists[i-1] != NULL)
            nums[++numsSize] = lists[i-1];  // 将所有非空链表的头节点加入堆
    }
    CreateHeap(nums);
    while(numsSize >= 1){
        tail->next = nums[1];  // 取出堆顶(最小值)
        tail = nums[1];
        if(tail == NULL)
            break;
        if(tail->next == NULL) // 如果这条链表已经空了，用堆底最后一个元素替换堆顶
            nums[1] = nums[numsSize--];     
        else
            nums[1] = tail->next;// 否则用此链表的下一个节点替换堆顶
        sink(nums, 1);// 调整堆，恢复最小堆性质
    }
    return head->next;
}

/*算法：
构建最小堆，内部元素为所有k个链表的头节点
每次取出堆顶(最小值),并将此元素所处链表向下移动，将下一个头节点移入堆中
直到堆空为止

时间复杂度：
遍历所有元素->n
每个元素都要进行sink操作：n*logk
总时间复杂度：O(n*logk)
*/