int removeDuplicates(int* nums, int numsSize) {
    int re_length = 0;
    int *re_nums = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize;i++){
        if(i != 0 && nums[i] == nums[i - 1]){
            continue;
        }
        re_nums[re_length++] = nums[i];
    }
    for (int i = 0; i < re_length;i++){
        nums[i] = re_nums[i];
    }
    free(re_nums);
    return re_length;
}