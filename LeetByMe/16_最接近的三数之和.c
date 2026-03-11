#include<stdio.h>
#include<math.h>
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int answer = nums[0] + nums[1] + nums[2];
    int i, j, k;
    
    for (i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        
        j = i + 1;
        k = numsSize - 1;
        
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target) {
                return target;
            }
            
            if (abs(sum - target) < abs(answer - target)) {
                answer = sum;
            }
            
            if (sum < target) {
                j++;
                while (j < k && nums[j] == nums[j-1]) j++;
            } else {
                k--;
                while (j < k && nums[k] == nums[k+1]) k--;
            }
        }
    }
    return answer;
}
