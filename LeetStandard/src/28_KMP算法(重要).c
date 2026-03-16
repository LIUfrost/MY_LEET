// 核心武器：计算 needle 的 next 数组（前缀表）
void getNext(int* next, const char* s, int len) {
    int j = 0; // j 代表“最长相等前后缀的长度”，也指向前缀的末尾
    next[0] = 0; // 第一个字符的前缀表肯定是 0
    
    for (int i = 1; i < len; i++) {
        // 1. 如果不匹配，j 就要顺着 next 数组不断回退，直到遇到相等的字符或者退回起点
        while (j > 0 && s[i] != s[j]) {
            j = next[j - 1]; 
        }
        // 2. 如果匹配，j 就往前走一步
        if (s[i] == s[j]) {
            j++;
        }
        // 3. 把当前 j 的值记录在 next 数组里
        next[i] = j;
    }
}

int strStr(char * haystack, char * needle) {
    int haylen = strlen(haystack);
    int needlen = strlen(needle);
    
    if (needlen == 0) return 0;
    
    // 动态分配 next 数组
    int* next = (int*)malloc(sizeof(int) * needlen);
    getNext(next, needle, needlen);
    
    int j = 0; // j 负责在 needle 里游走
    for (int i = 0; i < haylen; i++) { // i 负责在 haystack 里游走（永远不回头！）
        
        // 1. 如果不匹配，needle 指针 (j) 顺着 next 数组回退
        while (j > 0 && haystack[i] != needle[j]) {
            j = next[j - 1];
        }
        
        // 2. 如果匹配，needle 指针往前走一步
        if (haystack[i] == needle[j]) {
            j++;
        }
        
        // 3. 如果 j 走到了 needle 的尽头，说明全匹配上了！
        if (j == needlen) {
            free(next); // 释放内存，好习惯
            return i - needlen + 1; // 返回起始坐标
        }
    }
    
    free(next);
    return -1;
}
/*算法：
next数组的本质：对每个数字，存储的是，
    在P[0...i]这个子串中，最长的既是前缀又是后缀的连续子串的长度。
*/