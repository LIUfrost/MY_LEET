int removeElement(int* nums, int numsSize, int val) {
    int slow=0,fast=0;
    for(fast;fast<numsSize;fast++)
    {
        if(nums[fast]!=val)
        {
            nums[slow]=nums[fast];
            slow++;

        }
    }
    return slow;
}
