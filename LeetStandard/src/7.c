#include <stdio.h>
#include <limits.h>

//def主函数
int reverse(int x) {
    if (x == INT_MIN) return 0;
    
    int rev = 0;
    while (x != 0) {
        if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
            return 0;
        }
        int digit = x % 10;
        x /= 10;
        rev = rev * 10 + digit;
    }
    return rev;
}

//def客户端
int main() {
    int num;
    printf("请输入整数: ");
    scanf("%d", &num);
    
    int result = reverse(num);
    printf("反转结果: %d\n", result);
    
    return 0;
}

/*算法：
略;
注意溢出检测！！！
*/