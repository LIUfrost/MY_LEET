char* longestCommonPrefix(char** strs, int strsSize) {
    int long_common = 0;
    int if_stop = 1;
    int min_length = strlen(strs[0]);
    char* LC;
    for(int i = 0;i< strsSize;i++){
        if(strlen(strs[i]) < min_length){
            min_length = strlen(strs[i]);
        }
    }
    for(int i = 0;i< min_length;i++){
        for(int j = 0;j<strsSize - 1;j++){
            if(strs[j][i] != strs[j+1][i]){
                if_stop = 0;
                break;
            }
        }
        if(!if_stop){
            break;
        }
        long_common ++;
    }
    LC = malloc(sizeof(char) * (long_common+1));
    for(int k = 0;k<long_common;k++){
        LC[k] = strs[0][k];
    }
    LC[long_common] = '\0';
    return LC;
    
}