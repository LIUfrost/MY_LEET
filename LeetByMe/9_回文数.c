#include<stdio.h>
#include<string.h>

int isPalindrome(int x) {
    int x1 = x;
    int length = 0;
    int detect_num = 0, _ = 0;
    if(x < 0){
        return 0;
    }
    while(x1>0){
        x1 = x1/10;
        length ++ ;
    }
    detect_num = length / 2;
    for(_ = 0 ; _<detect_num ; _++){
        int i = pow(10,(_)), j = pow(10,(length - 1 - _));
        if(x/i%10 != (x/j)%10){
            return 0;
        }
    }
    return 1;
    
}