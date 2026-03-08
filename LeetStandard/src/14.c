char* longestCommonPrefix(char** strs, int strsSize) {
    char* s0 = strs[0];
    for (int j = 0; s0[j]; j++) { // 从左到右
        for (int i = 0; i < strsSize; i++) { // 从上到下
            if (strs[i][j] != s0[j]) { // 这一列有字母缺失或者不同
                s0[j] = '\0'; // 0 到 j-1 是公共前缀
                return s0;
            }
        }
    }
    return s0;
}

