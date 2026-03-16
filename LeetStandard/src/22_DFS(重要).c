// 回溯法求解
#define MAX_SIZE 1430  // 卡特兰数: 1, 1, 2, 5, 14, 42, 132, 429, 1430
void generate(int left, int right, int n, char *str, int index, char **result, int *returnSize) {
    if (index == 2 * n) { // 当前长度已达2n
        result[(*returnSize)] =  (char*)calloc((2 * n + 1), sizeof(char));
        strcpy(result[(*returnSize)++], str);
        return;
    }
    // 如果左括号数量不大于 n，可以放一个左括号
    if (left < n) {
        str[index] = '(';
        generate(left + 1, right, n, str, index + 1, result, returnSize);
    }
    // 如果右括号数量小于左括号的数量，可以放一个右括号
    if (right < left) {
        str[index] = ')';
        generate(left, right + 1, n, str, index + 1, result, returnSize);
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int *returnSize) {
    char *str = (char*)calloc((2 * n + 1), sizeof(char));
    char **result = (char **)malloc(sizeof(char *) * MAX_SIZE);
    *returnSize = 0;
    generate(0, 0, n, str, 0, result, returnSize);
    return result;
}