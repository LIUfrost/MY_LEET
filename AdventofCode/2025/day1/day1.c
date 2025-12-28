#include"C:\1.CODE\GIT\MY_LEET\include\common.h"

int main(){
    FILE *fp;
    int c;
    int choice = 0;
    int num = 50,pin = 0;
    fp = fopen("C:/1.CODE/GIT/MY_LEET/AdventofCode/2025/day1/data", "r");
    if(!fp){
        printf("not open the file");
        return 0;
    }
    while((c = getc(fp))!=EOF){
        int num0 = 0;
        if((char)c == ' '){
            continue;
        }
        if((char)c == 'L'){
            choice = -1;
        }
        else if((char)c == 'R'){
            choice = 1;
        }
        while(isdigit(c = getc(fp)) && c != EOF) {
            num0 = num0 * 10 + (c - '0');
        }
        int oldnum = num;
        num += (choice*num0);
        if(oldnum*num<0){
            pin++;
        }
        if(num == 0){
            pin++;
        }
        pin += fabs(num / 100);
        num = num % 100;
        if(num < 0){
            num += 100;
        }
        
        if(c != EOF && !isdigit(c)) {
            ungetc(c, fp);
        }
    }
    printf("%d", pin);
    return 0;
}