// 优化一：如果 nums[i] 与后面最小的两个数相加 nums[i]+nums[i+1]+nums[i+2]>0，
// 那么后面不可能存在三数之和等于 0，break 外层循环。

// 优化二：如果 nums[i] 与后面最大的两个数相加 nums[i]+nums[n−2]+nums[n−1]<0，
// 那么内层循环不可能存在三数之和等于 0，但继续枚举，nums[i] 可以变大，所以后面还有机会找到三数之和等于 0，continue 外层循环。

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int **ans = malloc(numsSize * numsSize * sizeof(int*));
    *returnColumnSizes = malloc(numsSize * numsSize * sizeof(int));
    int m = 0;
    for (int i = 0; i < numsSize - 2; i++) {
        int x = nums[i];
        if (i > 0 && x == nums[i - 1]) continue;
        if (x + nums[numsSize - 2] + nums[numsSize - 1] < 0) continue;  // 优化2
        if (x + nums[i + 1] + nums[i + 2] > 0) break;   // 优化1
        int j = i + 1;
        int k = numsSize - 1;
        while (j < k) {
            int temp = x + nums[j] + nums[k];
            if(temp > 0 ) {
                k--;
            } else if (temp < 0) {
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

/*算法：
和我自己写的一样
*/