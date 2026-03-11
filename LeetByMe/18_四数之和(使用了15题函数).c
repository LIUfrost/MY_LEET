#include<stdio.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int target,int* returnSize, int** returnColumnSizes) {
    int **ans = malloc(numsSize * numsSize * sizeof(int*));
    *returnColumnSizes = malloc(numsSize * numsSize * sizeof(int));
    int m = 0;
    for (int i = 0; i < numsSize - 2; i++) {
        int x = nums[i];
        if (i > 0 && x == nums[i - 1]) continue;
        //if (x + nums[numsSize - 2] + nums[numsSize - 1] < 0) continue;  // 优化2
        //if (x + nums[i + 1] + nums[i + 2] > 0) break;   // 优化1
        int j = i + 1;
        int k = numsSize - 1;
        while (j < k) {
            long temp = (long)x + nums[j] + nums[k];
            if(temp > target ) {
                k--;
            } else if (temp < target) {
                j++;
            } else {
                int* tuple = malloc(3 * sizeof(int));
                tuple[0] = x;
                tuple[1] = nums[j];
                tuple[2] = nums[k];
                ans[m] = tuple;
                (*returnColumnSizes)[m++] = 3;
                for (j++; j < k && nums[j] == nums[j - 1]; j++);
                for (k--; k > j && nums[k] == nums[k + 1]; k--);
            }
        }
    }
    *returnSize = m;
    return ans;
}


int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize,sizeof(int), cmp);

    int **ans = malloc(sizeof(int *) * numsSize * (numsSize-1) * (numsSize-2) * (numsSize-3) / 24);
    *returnColumnSizes = malloc(sizeof(int ) * numsSize * (numsSize-1) * (numsSize-2) * (numsSize-3) / 24);
    int size = 0;
    for (int i = 0; i < numsSize - 3;i++){
        if(i>0 && nums[i] == nums[i-1])   continue;

        int returnSize_three;
        int* returnColumnSizes_three;
        int **ans_three = threeSum(nums + i+1, numsSize - i-1, target - nums[i], &returnSize_three, &returnColumnSizes_three);
        if(returnSize_three == 0){continue;}

        for (int j = 0; j < returnSize_three;j++){
            ans[size] = malloc(4 * sizeof(int));
            ans[size][0] = nums[i];
            for (int k = 0; k < 3;k++){
                ans[size][k + 1] = ans_three[j][k];
            }
            size++;
        }
        // 释放内存
        for (int j = 0; j < returnSize_three;j++){
            free(ans_three[j]);
        }
        free(ans_three);
        free(returnColumnSizes_three);
    }
    for (int i = 0; i < size;i++){
        (*returnColumnSizes)[i] = 4;
    }
    *returnSize = size;
    return ans;
}