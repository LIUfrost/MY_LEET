#include"C:\1.CODE\GIT\MY_LEET\include\common.h"
#define MAXI(a, b) ((a) > (b) ? (a) : (b))

//def检测是否在子串中
int ifInChar(char *p,char s){
    char *p0 = p;
    while(*p0 != '\0'){
        if(*p0 == s){
            return 1;
        }
        p0++;
    }
    return 0;
}

//def主函数
long lengthOfLongestSubstring(char* s) {
    long size = strlen(s);
    if(size == 0){
        return 0;     // 边界条件
    }
    long MAX = 0,max = 0; // def存储最大子串的长度
    int i = 0;//def用来定位s0指针
    char *s0 = s;
    char *Sub = malloc(sizeof(char) * (size + 1));// 预留出'\0'的位置
    *Sub = '\0';
    while(*s0 != '\0'){
        int Inchar = ifInChar(Sub, *s0);
        if(Inchar == 1){
            Sub[0] = '\0';
            MAX = MAXI(MAX, max);
            max = 0;
            s0 = s + i;
            i++;
        }
        else if(Inchar == 0){
            Sub[max++] = *s0;
            Sub[max] = '\0';
        }
        s0++;
    }
    MAX = MAXI(MAX, max);
    return MAX;
}

//def测试客户端
int main(){
    char p[2] = " ";
    long answer = lengthOfLongestSubstring(p);
    printf("%ld", answer);
    return 0;
}