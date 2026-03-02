#include<limits.h>

int myAtoi(char* s) {
    char *s_iter = s;
    int s_con = 0;
    int neg_or_pos = 1;
    // 1.跳过前面空格
    while(*s_iter == ' '){
        s_iter++;
    }
    // 2.判断正负
    if(*s_iter == '-'){
        neg_or_pos = 0;
        s_iter++;
    }
    else if(*s_iter == '+'){
        s_iter++;
    }
    // 3.开始计数
    while(*s_iter){
        if(*s_iter >= '0' && *s_iter <='9'){
            int _ = *s_iter - '0';
            // 判断是否越界
            if(neg_or_pos == 1 && s_con>(INT_MAX-_)/10){
                return INT_MAX;
            }
            else if(neg_or_pos == 0 &&-s_con<(INT_MIN+_+1)/10){  //!注意这里要加1
                return INT_MIN;
            }
            s_con = s_con * 10 + _;
            s_iter++;
        }
        else{
            break;
        }
    }
    if(neg_or_pos == 0){
        s_con = -s_con;
    }
    return s_con;
}