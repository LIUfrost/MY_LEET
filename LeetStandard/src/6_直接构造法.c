#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//def主函数
char * convert(char * s, int numRows){
    int n = strlen(s), r = numRows;
    if (r == 1 || r >= n) {
        return s;
    }
    int t = r * 2 - 2;
    char * ans = (char *)malloc(sizeof(char) * (n + 1));
    int pos = 0;
    for (int i = 0; i < r; ++i) { // 枚举矩阵的行
        for (int j = 0; j + i < n; j += t) { // 枚举每个周期的起始下标
            ans[pos++] = s[j + i]; // 当前周期的第一个字符
            if (0 < i && i < r - 1 && j + t - i < n) {
                ans[pos++] = s[j + t - i]; // 当前周期的第二个字符
            }
        }
    }
    ans[pos] = '\0';
    return ans;
}

//def客户端
int main() {
    // 测试用例
    char* tests[] = {
        "PAYPALISHIRING",  // 测试1
        "ABCDEFG",         // 测试2
        "A",               // 测试3
        "HELLO",           // 测试4
        "123456789"        // 测试5
    };
    
    int numRows[] = {3, 2, 2, 3, 4};
    
    printf("Z字型变换测试:\n");
    printf("====================\n");
    
    for (int i = 0; i < 5; i++) {
        char* result = convert(tests[i], numRows[i]);
        printf("测试 %d:\n", i+1);
        printf("  输入: s=\"%s\", numRows=%d\n", tests[i], numRows[i]);
        printf("  输出: \"%s\"\n\n", result);
        free(result);
    }
    
    return 0;
}
