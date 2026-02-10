//def主函数
char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n <= 1) {
        char* res = malloc(n + 1);
        strcpy(res, s);
        return res;
    }
    
    int start = 0, max_len = 1;
    
    for (int i = 0; i < n; i++) {
        // 奇数长度回文
        int len1 = expand(s, i, i, n);
        // 偶数长度回文
        int len2 = expand(s, i, i + 1, n);
        
        int len = len1 > len2 ? len1 : len2;
        if (len > max_len) {
            max_len = len;
            start = i - (len - 1) / 2;
        }
    }
    
    char* result = malloc(max_len + 1);
    strncpy(result, s + start, max_len);
    result[max_len] = '\0';
    return result;
}

//def扩展函数：返回以left,right为中心的回文长度
int expand(char* s, int left, int right, int n) {
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;  // (right-1) - (left+1) + 1
}