/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** charadd(int** answer, int* need_add, int* count, int* capacity) {
    // 如果当前容量不足，扩容
    if (*count >= *capacity) {
        *capacity *= 2;
        answer = (int**)realloc(answer, sizeof(int*) * (*capacity));
    }
    
    // 分配新三元组的空间
    answer[*count] = (int*)malloc(sizeof(int) * 3);
    answer[*count][0] = need_add[0];
    answer[*count][1] = need_add[1];
    answer[*count][2] = need_add[2];
    
    (*count)++;
    return answer;
}

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // nums:原来的数组；numsSize:原来的数组大小；returnSize:返回了多少个数组；
    // returnColumnSizes:每个子数组的长度组成的数组(对于本题都是3)
    qsort(nums, numsSize, sizeof(int), compare);
    int i = 0,j = 0,k = numsSize - 1;
    int capacity = 10;
    int **answer = (int**)malloc(sizeof(int*) * capacity);
    int count = 0;
    

    for(i;i<numsSize-2;i++){
        j = i + 1;
        k = numsSize - 1;
        int target = -nums[i];
        if(i>0 && nums[i] == nums[i - 1]){   // 对于第一个数如果和之前的重复了，就跳过
            continue;
        }
        while(j < k){    // 对第二个和第三个数：采用从头尾往中间靠拢的双指针算法
            if(nums[j] + nums[k] > target){
                k--;
            }
            else if(nums[j] + nums[k] < target){
                j++;
            }
            else{
                int need_add[3] = {nums[i],nums[j],nums[k]};
                answer = charadd(answer, need_add, &count, &capacity);
                while(j<k && nums[k] == nums[k-1]){
                    k--;
                }
                while(j<k && nums[j] == nums[j+1]){
                    j++;
                }
                j++;
                k--;
            }
        }
    }
    *returnSize = count;
    *returnColumnSizes = (int*)malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        (*returnColumnSizes)[i] = 3;
    }
    return answer;
}

/*算法：
从原来的O(n^3)优化到O(n^2)
*/