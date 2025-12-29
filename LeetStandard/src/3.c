//TAG:子串最大长度
//TAG:滑动窗口

#include <string.h>
#include<stdio.h>

//def主函数
int lengthOfLongestSubstring(char* s) {
    int lastIndex[256];
    for (int i = 0; i < 256; i++)
        lastIndex[i] = -1;

    int maxLen = 0;
    int left = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        char c = s[right];

        // If character seen inside current window
        if (lastIndex[c] >= left) {
            left = lastIndex[c] + 1;
        }

        lastIndex[c] = right;

        int windowLen = right - left + 1;
        if (windowLen > maxLen)
            maxLen = windowLen;
    }

    return maxLen;
}

//def测试客户端
int main(){
    char p[20] = "hksdgasd";
    long answer = lengthOfLongestSubstring(p);
    printf("%ld", answer);
    return 0;
}