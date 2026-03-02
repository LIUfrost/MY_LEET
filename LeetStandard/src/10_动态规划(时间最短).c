
bool isMatch(char* s, char* p) {
    int n1 = strlen(s);
    int n2 = strlen(p);
    int dp[n1 + 1][n2 + 1];
    memset(dp,0,sizeof(dp)); dp[0][0] = 1;
    for(int i = 0;i <= n1;i++){
        for(int j = 1;j <= n2;j++){
            if(p[j - 1] == '*'){
                //匹配0个结果
                dp[i][j] |= dp[i][j - 2];
                //匹配多个结果
                if(i > 0 && (p[j - 2] == s[i - 1] || p[j - 2] == '.')) dp[i][j] |= dp[i - 1][j];
            }
            else{
                if(i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')){
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
    }
    return dp[n1][n2];
}

/*算法：
时间复杂度————O(N*M)
其中 m 和 n 分别是字符串 s 和 p 的长度
*/