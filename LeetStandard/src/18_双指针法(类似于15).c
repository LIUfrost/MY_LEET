#include<stdio.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 4) return NULL;
    
    qsort(nums, numsSize, sizeof(int), cmp);
    
    // 预分配结果空间（根据题目数据范围调整，2000通常足够）
    int maxAns = 2000;
    int** ans = malloc(maxAns * sizeof(int*));
    *returnColumnSizes = malloc(maxAns * sizeof(int));
    
    for (int i = 0; i < numsSize - 3; i++) {
        // 去重：跳过相同的首元素
        if (i > 0 && nums[i] == nums[i-1]) continue;
        
        // 剪枝1：当前最小四数之和大于target，后续都大
        if ((long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
        
        // 剪枝2：当前最大四数之和小于target，当前i不行，换下一个i
        if ((long)nums[i] + nums[numsSize-3] + nums[numsSize-2] + nums[numsSize-1] < target) continue;
        
        for (int j = i + 1; j < numsSize - 2; j++) {
            // 去重：跳过相同的第二元素
            if (j > i + 1 && nums[j] == nums[j-1]) continue;
            
            // 剪枝
            if ((long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
            if ((long)nums[i] + nums[j] + nums[numsSize-2] + nums[numsSize-1] < target) continue;
            
            int left = j + 1, right = numsSize - 1;
            while (left < right) {
                long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                
                if (sum == target) {
                    // 记录结果
                    ans[*returnSize] = malloc(4 * sizeof(int));
                    ans[*returnSize][0] = nums[i];
                    ans[*returnSize][1] = nums[j];
                    ans[*returnSize][2] = nums[left];
                    ans[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;
                    
                    // 去重：跳过相同的第三、四元素
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    
    return ans;
}

/*算法：
类似于15题
略
时间复杂度O(n^3)
*/