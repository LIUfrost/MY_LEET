#include<stdio.h>
void myFunc();
int main(){
	int *p = NULL;
    *p = 10;  // 访问空指针
    return 0;
}