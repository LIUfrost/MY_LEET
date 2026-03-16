bool isValid(char* s) {
    int length = strlen(s);
    if(length % 2 != 0){
        return false;
    }
    char *stack = malloc(sizeof(char) * (length + 1));
    int i = 0; // 用于指向栈的当前索引
    while(*s){
        stack[i] = *s;
        bool Valid = i>0 && ((stack[i] == ')' && stack[i-1] == '(') || (stack[i] == ']' && stack[i-1] == '[') || (stack[i] == '}' && stack[i-1] == '{'));
        if(Valid){
            i = i-1;
            s++;
            continue;
        }
        i++;
        s++;
    }
    if(i == 0){
        return true;
    }
    else{
        return false;
    }
}