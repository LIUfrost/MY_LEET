char* path; // 当前正在构筑的字母组合(如"ad")
int pathSize;// 当前path的长度(已经选了几个字母)
char** ans;// 存储所有结果的数组(答案)
int ansSize;// 已经找到多少个有效结合
char* map[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
// 以输入"23"为例
void dfs(char* digits) {
    int len = strlen(digits);
    if (pathSize == len) {
        ans[ansSize] = malloc(sizeof(int) * (len + 1));
        for (int i = 0; i < len; i++) {
            ans[ansSize][i] = path[i];
        }
        ans[ansSize][len] = '\0';
        ansSize++;
        return;
    }
    int num = digits[pathSize] - '2';   // 找到他在map中的索引(例如此时2为0)
    char* temp = map[num]; // temp = "abc"
    for (int i = 0; i < strlen(temp); i++) {   // 先遍历a,b,c
        path[pathSize++] = temp[i];  // 先选'a'
        dfs(digits); // 递归处理下一个数字
        pathSize--;  // 回溯，插销操作
    }
}
char** letterCombinations(char* digits, int* returnSize) {
    pathSize = 0;
    ansSize = 0;
    ans = malloc(sizeof(int*) * 1000000);
    path = malloc(sizeof(int) * 1000000);
    dfs(digits);

    *returnSize = ansSize;
    return ans;
}
/*算法：
深度优先算法
过程已在注释中阐明
*/