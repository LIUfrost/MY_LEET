#include <stdio.h>
#include <limits.h>

//def主函数
int reverse(int x) {
    int pos_or_neg;
    int x_converse = 0;
    if(x>=0){
        pos_or_neg = 1;
    }
    else{
        pos_or_neg = -1;
    }
    if (x == INT_MIN) return 0;     //!防止abs后int类型溢出
    int pos_x = abs(x);
    int if_0 = 0;    // 判断转换后开头是否为0
    while(pos_x != 0){
        if(pos_x%10 != 0){
            if_0 = 1;
        }
        if(if_0){
            //!在计算前就判断是否会溢出（题目只要求使用int类型，反转后可能出现溢出情况）
            // INT_MAX = 2,147,483,647；INT_MIN = -2,147,483,648
            if (x_converse > INT_MAX/10 || (x_converse == INT_MAX/10 && (pos_x%10) > 7))
                return 0;
            if (x_converse < INT_MIN/10 || (x_converse == INT_MIN/10 && (pos_x%10)< -8))
                return 0;
            x_converse = x_converse * 10 + pos_x % 10;
        }
        pos_x = pos_x / 10;
    }
    if(pos_or_neg == -1){
        x_converse = -x_converse;
    }
    return x_converse;
}

//def测试客户端
int main() {
    int num;
    printf("请输入整数: ");
    scanf("%d", &num);
    
    int result = reverse(num);
    printf("反转结果: %d\n", result);
    
    return 0;
}