/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>

char **gp(int i, int j, int *returnSize){
    if((j<i) || (i == 0 && j == 0)){
        *returnSize = 0;
        return NULL;
    }
    if(i==0){
        *returnSize = 1;
        char **ans = malloc(sizeof(char *));
        ans[0] = malloc(sizeof(char) * (j + 1));
        for (int n = 0; n < j;n++){
            ans[0][n] = ')';
        }
        ans[0][j] = '\0';
        return ans;
    }

    int return1, return2;
    char **ans1 = gp(i - 1, j, &return1);
    char **ans2 = gp(i, j - 1, &return2);
    *returnSize = return1 + return2;
    char **ans = malloc(sizeof(char *) * (return1 + return2));
    for (int n = 0; n < return1;n++){
        ans[n] = malloc(sizeof(char) * (i + j + 1));
        ans[n][0] = '(';
        strcpy(ans[n] + 1, ans1[n]);
        ans[n][i + j] = '\0';
    }
    for (int n = return1; n < (return1 + return2);n++){
        ans[n] = malloc(sizeof(char) * (i + j + 1));
        ans[n][0] = ')';
        strcpy(ans[n] + 1, ans2[n-return1]);
        ans[n][i + j] = '\0';
    }

    for (int n = 0; n < return1; n++) {
        free(ans1[n]);
    }
    free(ans1);
    
    for (int n = 0; n < return2; n++) {
        free(ans2[n]);
    }
    free(ans2);
    return ans;
}

char** generateParenthesis(int n, int* returnSize) {
    char **ans = gp(n, n, returnSize);
    return ans;
}