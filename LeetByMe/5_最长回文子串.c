//!解法错误，对于长串相同字符出错

#include"C:\1.CODE\GIT\MY_LEET\include\common.h"

int s_len = 0;
char* s_static;
char re_ch(char *s){
    if (s < s_static || s >= s_static + s_len){
        return '\0';
    }
    else{
        return *s;
    }
}

char* longestPalindrome(char* s) {
    s_len = strlen(s);
    s_static = s;
    int Pal_len = 1;
    char *answer = s;
    char *s0 = s;
    int Pal = 0;
    while(*s0){
        if (Pal != 0 && re_ch(s0) == re_ch(s0 - Pal - 2)) {
            Pal += 2;
        } else {
            // 继承失败，必须重算 Pal
            if (re_ch(s0) == re_ch(s0 - 1)) {
                Pal = 1;
            }
            else if (re_ch(s0) == re_ch(s0 - 2)) {
                Pal = 2;
            }
            else {
                Pal = 0;
            }
        }

        // 更新答案
        if (Pal + 1> Pal_len) {
            Pal_len = Pal + 1;
            answer = s0 - Pal;
        }

        s0++;
    }
    char *answer_ = malloc(sizeof(char) * (Pal_len+1));
    for (int i = 0; i < Pal_len;i++){    
        answer_[i] = answer[i];                               
    }
    answer_[Pal_len] = '\0';
    return answer_;
}

int main(){
    char s[] = "babad";
    char *s0 = longestPalindrome(s);
    printf("%s", s0);
    return 0;
}