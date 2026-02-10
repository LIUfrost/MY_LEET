//TAG:Manacher算法

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//def主函数
char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n <= 1) {
        char* res = malloc(n + 1);
        strcpy(res, s);
        return res;
    }

    // 预处理
    int t_len = 2 * n + 3;
    char* t = malloc(t_len + 1);
    t[0] = '^';
    for (int i = 0; i < n; i++) {
        t[2*i + 1] = '#';
        t[2*i + 2] = s[i];
    }
    t[2*n + 1] = '#';
    t[2*n + 2] = '$';
    t[2*n + 3] = '\0'; // ^代表头; $代表尾

    // Manacher 算法
    int* p = calloc(t_len, sizeof(int));
    int c = 0, r = 0;                       // c代表此时的镜像点，p[i]代表i处的臂长，r代表最右侧点(c+p[c])
    int max_len = 0, center_idx = 0;
    
    for (int i = 1; i < t_len - 1; i++) {
        int mirror = 2 * c - i;
        if (i < r) {
            p[i] = (r - i < p[mirror]) ? r - i : p[mirror];  
        }
        
        while (t[i + (1 + p[i])] == t[i - (1 + p[i])]) {
            p[i]++;                // 如果此处p[i]增加了，那么右边界r必然会更新！
        }
        
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
        
        if (p[i] > max_len) {
            max_len = p[i];
            center_idx = i;
        }
    }
    
    // 提取结果
    int start = (center_idx - max_len) / 2;
    char* result = malloc(max_len + 1);
    strncpy(result, s + start, max_len);        // 直接从原字符串处理即可
    result[max_len] = '\0';
    
    free(t);
    free(p);
    return result;
}


//def测试客户端
int main() {
    printf("=== 最长回文子串查找器 ===\n");
    printf("输入 'exit' 或 'quit' 退出程序\n\n");
    
    while (1) {
        char input[1024];
        printf("请输入字符串 (最大长度 1000): ");
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        
        // 移除换行符
        input[strcspn(input, "\n")] = '\0';
        
        // 检查退出条件
        if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0) {
            printf("再见！\n");
            break;
        }
        
        if (strlen(input) == 0) {
            printf("输入不能为空！\n\n");
            continue;
        }
        
        printf("\n输入: %s\n", input);
        
        // 计算并计时
        clock_t start = clock();
        char* result = longestPalindrome(input);
        clock_t end = clock();
        
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        printf("最长回文子串: %s\n", result);
        printf("长度: %zu\n", strlen(result));
        printf("计算时间: %.6f 秒\n", time_taken);
        printf("------------------------\n\n");
        
        free(result);
    }
    
    return 0;
}
/* 算法：
为了表述方便，我们定义一个新概念臂长，表示中心扩展算法向外扩展的长度。
如果一个位置的最大回文字符串长度为 2 * length + 1 ，其臂长为 length。

当在位置 i 开始进行中心拓展时，我们可以先找到 i 关于 j 的对称点 2 * j - i。
那么如果点 2 * j - i 的臂长等于 n，我们就可以知道，点 i 的臂长至少为 min(j + length - i, n)。
那么我们就可以直接跳过 i 到 i + min(j + length - i, n) 这部分，从 i + min(j + length - i, n) + 1 开始拓展。
我们只需要在中心扩展法的过程中记录右臂在最右边的回文字符串，将其中心作为 j，在计算过程中就能最大限度地避免重复计算。

那么现在还有一个问题：如何处理长度为偶数的回文字符串呢？

我们可以通过一个特别的操作将奇偶数的情况统一起来：
我们向字符串的头尾以及每两个字符中间添加一个特殊字符 #，比如字符串 aaba 处理后会变成 #a#a#b#a#。
那么原先长度为偶数的回文字符串 aa 会变成长度为奇数的回文字符串 #a#a#，
而长度为奇数的回文字符串 aba 会变成长度仍然为奇数的回文字符串 #a#b#a#，我们就不需要再考虑长度为偶数的回文字符串了。

注意这里的特殊字符不需要是没有出现过的字母，我们可以使用任何一个字符来作为这个特殊字符。这是因为，当我们只考虑长度为奇数的回文字符串时，每次我们比较的两个字符奇偶性一定是相同的，所以原来字符串中的字符不会与插入的特殊字符互相比较，不会因此产生问题。

作者：力扣官方题解
链接：https://leetcode.cn/problems/longest-palindromic-substring/solutions/255195/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/