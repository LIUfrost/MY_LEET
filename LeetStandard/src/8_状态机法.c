#include <ctype.h>
#include <limits.h>

int myAtoi(char* s) {
    // 状态定义：0=start, 1=signed, 2=number, 3=end
    int state = 0;
    int sign = 1;
    long ans = 0;
    
    // 状态转移表
    int table[4][4] = {
        // space, sign, number, other
        {0, 1, 2, 3},  // start
        {3, 3, 2, 3},  // signed
        {3, 3, 2, 3},  // number
        {3, 3, 3, 3}   // end
    };
    
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        
        // 获取列
        int col;
        if (isspace(c)) col = 0;
        else if (c == '+' || c == '-') col = 1;
        else if (isdigit(c)) col = 2;
        else col = 3;
        
        state = table[state][col];
        
        if (state == 2) {  // number状态
            int digit = c - '0';
            
            if (sign == 1) {
                if (ans > (INT_MAX - digit) / 10) {
                    return INT_MAX;
                }
            } else {
                if (ans > (long)(-INT_MIN) - digit) {
                    return INT_MIN;
                }
            }
            
            ans = ans * 10 + digit;
        }
        else if (state == 1) {  // signed状态
            sign = (c == '+') ? 1 : -1;
        }
        else if (state == 3) {  // end状态
            break;
        }
    }
    
    return sign * (int)ans;
}
