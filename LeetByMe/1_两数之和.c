//TAG:哈希表
//def应用哈希表
#include<stdio.h>
#include<stdlib.h>
#include "C:\1.CODE\GIT\MY_LEET\include\uthash.h"
//def主函数
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct hashTable {
        int key;
        int value;
        UT_hash_handle hh;   // 定义哈希表
    } *hashTable = NULL, *item, *tmpItem;
    // hashTable用于存储键值对；item用于辅助存储；tmpItem用于辅助删除

    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(hashTable, &nums[i], item);// 查找键nums[i]的值并返回item中，若没有找到，返回NULL
        if (item) {
            int* result = malloc(sizeof(int) * 2);
            result[0] = item->value;
            result[1] = i;
            *returnSize = 2;
            HASH_ITER(hh, hashTable, item, tmpItem) {
                HASH_DEL(hashTable, item);
                free(item);
            }
            return result;
        }
        item = malloc(sizeof(struct hashTable));
        // 到这一步说明键没有找到，则将键存储在Hash的值中，对应的键是target-键
        item->key = target - nums[i];
        item->value = i;
        HASH_ADD_INT(hashTable, key, item);
    }
    // 到这里说明并没有找到和为target的两个数
    HASH_ITER(hh, hashTable, item, tmpItem) {
        HASH_DEL(hashTable, item);
        free(item);
    }
    *returnSize = 0;
    // If no valid pair is found, return an empty array
    return malloc(sizeof(int) * 0);
}

//def客户端
int main(){
    int nums[5] = {1, 4, 65, 2, 6};
    int target = 8;
    int numsSize = 5;
    int *returnSize = malloc(sizeof(int));
    int *p;
    p = twoSum(nums, numsSize, target, returnSize);
    printf("%d,%d", p[0], p[1]);
    return 0;
}