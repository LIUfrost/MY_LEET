int removeElement(int* nums, int numsSize, int val) {
    int delete = 0;
    for (int i = 0; i < numsSize;i++){
        if (nums[i] == val){
            delete++;
            continue;
        }
        nums[i - delete] = nums[i];
    }
    return numsSize - delete;
}