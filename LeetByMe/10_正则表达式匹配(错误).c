bool isMatch(char* s, char* p) {
    char* s1 = s , *p1 = p;
    while(*s1 || *p1){
        bool _ = ((*s1 == '\0') && (*p1 != '\0')) || ((*p1 == '\0')&&(*s1 != '\0'));
        if(_) {
            return false;
        }
        if(*p1 == '.' || *s1 == *p1){
            s1++;
            p1++;
            continue;
        }
        else if(*p1 == '*'){
            if(*(p1 - 1) == '.'){
                *(p1 - 1) = *s1;
            }
            if(*(p1-1) != *(s1-1)){
                p1 ++;
                continue;
            }
            else{
                if(*(p1+1) != *(p1 - 1)){
                    while(*s1 == *(p1-1)){
                        s1++;
                    }
                    p1++;
                    continue;
                }
                else{
                    while(*s1 == *(p1-1)){
                        s1++;
                    }
                    p1++;
                    while(*p1 == *(s1 - 1)){
                        p1++;
                    }
                    continue;

                }
            }
        }
        else if(*p1 == *s1){
            s1++;
            p1++;
            continue;
        }
        else if(*p1 != *s1 && *(p1+1) == '*'){
            p1+=2;
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}