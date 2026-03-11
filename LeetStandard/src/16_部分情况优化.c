#include <stdlib.h> // for qsort()

int compare(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums,numsSize,sizeof(int),compare);
    int n=numsSize;
    int ans=INT_MAX/2;
    for(int i=0;i<numsSize-2;i++)
    {
        int x=nums[i];
        // 优化
        if(i>0&&x==nums[i-1])continue;
        // 优化
        int s=nums[i]+nums[i+1]+nums[i+2];
        if(s>target)
        {
            if(s-target<abs(ans-target))
            {
                ans=s;
            }
            break;// 最小的都不可，后面都不会
        }
        // 优化
        s=nums[i]+nums[n-2]+nums[n-1];
        if(s<target)
        {
            if(target-s<abs(target-ans))
            {
                ans=s;
            }
            continue;// 并非最大的，需要往下走
        }
        int left=i+1;
        int right=numsSize-1;
        while(left<right)
        {
            s=nums[i]+nums[left]+nums[right];
            if(abs(s-target)<abs(ans-target))
            {
                ans=s;
            }
            if(s==target)
            {
                return target;
            }
            else if(s>target)
            {
                right--;
            }
            else 
            {
                left++;
            }
        }
    }   
    return ans;
}
