int maxArea(int* height, int heightSize) {
 int left = 0;
    int right = heightSize - 1;
    int max_water = 0;
    
    while(left < right) {
        int width = right - left;
        int min_height = height[left] < height[right] ? height[left] : height[right];
        int current_water = width * min_height;
        //获取最大值
        if(current_water > max_water) {
            max_water = current_water;
        }
        //枚举
        if(height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max_water;
}

/*算法：
这个算法是盛最多水的容器问题的双指针解法：

初始化：左指针指向数组开头，右指针指向数组末尾，最大水量初始为0

循环收缩：当左指针小于右指针时：
计算当前宽度 = 右指针 - 左指针
计算当前高度 = 两指针指向高度的较小值
计算当前水量 = 宽度 × 高度，更新最大水量
移动较矮的指针（关键策略：保留较高边，才有机会找到更大面积）

返回结果：循环结束后返回记录的最大水量

核心思想：通过每次移动较短的边，逐步缩小搜索范围，保证不会错过最优解
*/