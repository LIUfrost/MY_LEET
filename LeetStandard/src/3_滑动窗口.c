//TAG:子串最大长度
//TAG:滑动窗口

#include <string.h>
#include<stdio.h>

//def主函数
int lengthOfLongestSubstring(char* s) {
    int hash[128] = {0};
    int i , j = 0;
    int Max = 0;
    int len = strlen(s);
    for(i = 0 ; i < len ; i++)
    {
        hash[s[i]]++;
        while(hash[s[i]] > 1)
        {
            hash[s[j]]--;
            j++;
        }
        if(i - j + 1 > Max)
            Max = i - j + 1;
    }
    return Max;
}

//def测试客户端
int main(){
    char p[20] = "hksdgasd";
    long answer = lengthOfLongestSubstring(p);
    printf("%ld", answer);
    return 0;
}

/* 算法：
这个算法通过滑动窗口技术解决无重复字符的最长子串问题。
整个过程就像用一个可以伸缩的橡皮筋在字符串上滑动，始终保持橡皮筋内的字符不重复，并记录下橡皮筋最长时的长度。

初始状态
左指针 j = 0，右指针 i = 0，窗口为空，最大长度 Max = 0
哈希数组 hash[128] 全部初始化为0，用于记录窗口内每个ASCII字符的出现次数

主循环：右指针 i 逐个遍历字符
对于字符串中的每个字符 s[i]：
扩展窗口：将 s[i] 加入窗口，hash[s[i]]++
检查重复：如果 hash[s[i]] > 1，说明 s[i] 在窗口中重复了
收缩窗口：
while(hash[s[i]] > 1) 循环，不断从窗口左侧移除字符
每次移除：hash[s[j]]--（减少该字符计数），j++（左指针右移）
直到 s[i] 在窗口中不再重复（hash[s[i]] == 1）
更新最大长度：计算当前窗口长度 i - j + 1，如果大于 Max 则更新

关键特性
窗口定义：[j, i] 闭区间内的子串始终无重复字符

哈希表作用：hash[ch] 的值表示字符 ch 在当前窗口中的出现次数

指针移动：
右指针 i 每次循环固定右移1位
左指针 j 只在发现重复时才向右移动（可能一次移动多位）

时间复杂度：每个字符最多被 i 访问一次、被 j 访问一次，整体 O(n)

终止条件
当右指针 i 遍历完整个字符串后，返回记录的最大长度 Max
*/