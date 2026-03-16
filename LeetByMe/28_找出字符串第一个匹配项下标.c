int strStr(char* haystack, char* needle) {
    int length1 = strlen(haystack), length2 = strlen(needle);
    char *hay_iter = haystack;
    char *nee_iter = needle;
    int seat;
    int ans = -1;
    for(seat = 0;seat<length1;seat ++){
        if(hay_iter[seat] == *nee_iter){
            ans = seat;
            for(int j = 1;j<length2;j++){
                if(hay_iter[seat+j] != nee_iter[j]){
                    ans = -1;
                    break;
                }
            }
        } 
        if(ans != -1){
            break;
        }
    }
    return ans;
}

/*算法：
时间复杂度:O(M*N)
*/