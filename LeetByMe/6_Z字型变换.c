char* convert(char* s, int numRows) {
    int len = strlen(s);
    char *s_Zconvert = malloc(sizeof(char) * (len + 1));
    char *s_convert = s_Zconvert;
    if(numRows == 1 || len <= numRows){         // 处理特殊情况
        strcpy(s_convert, s);
        return s_convert;
    }
    int rows = numRows, cols = (len / (2 * rows - 2)) + 1;
    char **convert = malloc(sizeof(char *) * (cols));
    for (int i = 0; i < cols;i++){
        convert[i] = calloc((2*rows - 2), sizeof(char));
    }
    char *s_iter = s;
    int i = 0, j = 0;
    while(*s_iter){
        convert[i][j] = *s_iter;
        s_iter++;
        j++;
        if(j%(2 * rows - 2) == 0){
            i++;
            j = 0;
        }
    }
    while(j<(2*rows-2)){
        convert[i][j++] = '\0';
    }
    i = 0, j = 0;
    while(j<rows){
        *s_Zconvert = convert[i][j];
        if(j != 0 && j != (rows - 1) && convert[i][2*rows -2 - j] != '\0'){
            s_Zconvert++;
            *s_Zconvert = convert[i][2 * rows-2 - j];
        }
        s_Zconvert++;
        i++;
        if(i == (cols) || convert[i][j] == '\0'){
            j++;
            i = 0;
        }
    }
    *s_Zconvert = '\0';
    return s_convert;
}