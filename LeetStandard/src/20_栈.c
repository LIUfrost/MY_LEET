
bool isValid(char* s) {
    int len = strlen(s); // 获取字符串实际长度
    char stack[len];     // 创建一个栈
    int top = -1;        // 栈顶指针初始化为 -1

    for (int i = 0; i < len; i++) {
        char c = s[i];
        // 如果是左括号，入栈
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else {
            // 如果是右括号，检查栈是否为空或者是否匹配
            if (top == -1) return false; // 栈空说明没有对应左括号
            char topChar = stack[top--]; // 弹出栈顶元素
            if ((c == ')' && topChar != '(') ||
                (c == ']' && topChar != '[') ||
                (c == '}' && topChar != '{')) {
                return false; // 不匹配则返回 false
            }
        }
    }

    return top == -1; // 最后栈应为空才表示全部匹配
}

/*算法：
栈
*/
