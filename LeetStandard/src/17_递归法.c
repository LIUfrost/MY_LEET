#include<stdio.h>

int size[8] = {3,3,3,3,3,4,3,4};
char letter[8] = {'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'};

char** letterCombinations(char* digits, int* returnSize) {
    // 处理空字符串
    if (digits == NULL || digits[0] == '\0') {
        *returnSize = 0;
        return NULL;
    }
    
    int length = strlen(digits);
    
    // 递归终止条件：只剩一个数字
    if (length == 1) {
        int first_size = size[*digits - '2'];
        char first_char = letter[*digits - '2'];
        
        *returnSize = first_size;
        char **answer = malloc(sizeof(char *) * first_size);
        
        for (int i = 0; i < first_size; i++) {
            answer[i] = malloc(sizeof(char) * 2);
            answer[i][0] = first_char + i;
            answer[i][1] = '\0';
        }
        return answer;
    }
    
    // 递归处理剩余数字 - 关键修复：使用局部变量并传递地址
    int last_return_size;
    char **last_return = letterCombinations(digits + 1, &last_return_size);
    
    int first_size = size[*digits - '2'];
    char first_char = letter[*digits - '2'];
    
    // 计算总组合数
    *returnSize = first_size * last_return_size;
    
    // 分配结果数组
    char **answer = malloc(sizeof(char *) * (*returnSize));
    
    // 组合第一个数字和后续结果
    for (int i = 0; i < first_size; i++) {
        for (int j = 0; j < last_return_size; j++) {
            int index = i * last_return_size + j;  // 你的思路：连续区域分配
            
            answer[index] = malloc(sizeof(char) * (length + 1));
            answer[index][0] = first_char + i;
            strcpy(answer[index] + 1, last_return[j]);
        }
    }
    
    // 释放递归结果
    for (int i = 0; i < last_return_size; i++) {
        free(last_return[i]);
    }
    free(last_return);
    
    return answer;
}

/*算法：
利用递归：
对digits + 1使用该函数，再把digits第一个数字所代表的字母依次加到每一个字符串上
时间复杂度：O(s^m * 4^N)
*/