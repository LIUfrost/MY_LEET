
bool isMatch(char * s, char * p){
    if (!*p) return !*s;
    bool first_match = *s && (*s == *p || *p == '.');
    if (*(p+1) == '*') {
        return isMatch(s, p+2) || (first_match && isMatch(++s, p));
    }
    else {
        return first_match && isMatch(++s, ++p);
    }
}

/*算法：
1.如果p为空，s也为空，返回true；s不为空，返回false

2.如果p+1不是‘*’：
    返回(++s,++p)匹配的bool

3.如果p+1是‘*’：
    i.若p+2和s一样，则中间的p和p+1可忽略，结果等于（s,p+2）匹配的bool
    ii.若不一样，则先检测当前s和p是否能匹配(*s == *p||*p = '.')
       若能匹配，则结果等于(++s,p)匹配的bool
    上述两种情况只要有一种匹配的上，则当前结果返回true
    
tp:时间复杂度————O(2^N)
*/