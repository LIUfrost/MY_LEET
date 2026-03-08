int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), cmp);
    int **ans = malloc(fmin(numsSize * sqrt(numsSize), 18000) * sizeof(int*));    
    int tabsize = abs(nums[0] * 2) + 1;  // 计算表大小
    bool tab[tabsize];                    // 创建布尔数组
    memset(tab, false, tabsize);          // 初始化为false
    int cnt = 0;
    int temp = 0;
    int lastx = 0, lasty = 0;

    for (int i = 0; i < tabsize; i++){
        for (lastx = lasty; lastx < numsSize; lastx++){
            if (nums[lastx] == i){
                tab[i] = true;  // 标记数值i存在
                while (++lastx < numsSize && nums[lastx-1] == nums[lastx]);   // 跳过重复的数值
                lasty = lastx;
                break;
            } else if (nums[lastx] > i) break;
        }  
    }
    lastx = lasty = -1e5 - 1;  // 初始化上次使用的值（很小的数）
    for (int x = 0; x < numsSize; x++) {
        if (lastx == nums[x]) continue;  // 跳过重复的x
        
        for (int y = x + 1; y < numsSize - 1; y++) {
            if (lasty == nums[y] && lastx == nums[x]) continue;  // 跳过重复的y
            
            temp = -(nums[x] + nums[y]);  // 计算需要的第三个数
            
            if (temp < nums[y]) break;     // 因为数组有序，如果temp < nums[y]，后面更大，不可能找到
            
            if (tab[temp] && temp >= nums[y+1]) {  // 检查temp是否存在且大于等于下一个数
                int *l = malloc(3 * sizeof(int));
                l[0] = nums[x];
                l[1] = nums[y];
                l[2] = temp;
                ans[cnt++] = l;
                lastx = nums[x];
                lasty = nums[y];
            }
        }
    }
    *returnSize = cnt;
    *returnColumnSizes = malloc(sizeof(int) * cnt);
    for(int i = 0; i < cnt; i++){
        (*returnColumnSizes)[i] = 3;
    }
    return ans;
}

/*算法：
这个算法使用了一种基于布尔表的哈希思想来寻找所有和为0的三元组。
整个流程可以分为四个主要步骤：

第一步：数组排序
算法首先对输入的整数数组进行快速排序，将所有数字按从小到大的顺序排列。
排序的目的是为了后续能有序地遍历数组，并方便处理重复元素。

第二步：构建存在性查找表
算法根据排序后第一个数的绝对值计算出查找表的大小（第一个数的绝对值乘以2再加1），
然后创建一个布尔类型的数组作为查找表，并将所有位置初始化为"不存在"状态。
接着，算法遍历这个查找表的每一个可能位置（从0到表大小-1），对于每个位置i，
它会在原数组中查找是否存在数值等于i的元素。如果找到了，就在查找表的第i个位置标记为"存在"，
并跳过数组中所有重复的相同数值，然后继续查找下一个位置i。这个过程最终得到了一个能快速查询某个数值是否存在于原数组中的查找表。

第三步：查找所有三元组
算法初始化两个变量来记录上一次使用的数值，用于去重。然后开始双重循环：
外层循环固定第一个数x，遍历数组的每一个位置。
如果当前x的值与上一次使用的x相同，则跳过这次循环，避免重复。

内层循环固定第二个数y，从x的下一个位置开始遍历。
同样地，如果当前y的值与上一次使用的y相同且x也相同，则跳过。

对于每一对(x, y)，算法计算出使三数之和为0所需要的第三个数temp = -(x + y)。
由于数组已经排序，如果temp小于当前的y，说明后面不可能找到合适的第三个数，直接跳出内层循环。

然后算法检查查找表中temp位置是否标记为"存在"，并且temp大于等于y的下一个数（这个条件是为了确保temp不会与y重复）。
如果条件满足，就找到了一个有效的三元组(x, y, temp)，将它们存储起来，并记录下当前的x和y用于后续去重。

第四步：返回结果
最后，算法将找到的三元组个数存入returnSize，为每个三元组分配一个长度为3的列大小数组，并返回存储所有三元组的指针数组。

这个算法的核心思想是用空间换时间，通过预先构建查找表，使得判断第三个数是否存在的时间复杂度降为O(1)，
但缺点是查找表的大小受限于数组中数值的范围，且无法处理负数索引的问题。
*/