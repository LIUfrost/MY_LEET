char five[5] = {' ','V','L','D',' '};
char one[5] = {' ','I','X','C','M'};

char* intToRoman(int num) {
    char *roman = malloc(sizeof(char) * 17);  //最大为3888，占16个字符
    char *r_i = roman;
    int length = 0, num1 = num;
    while(num1 > 0){
        num1 /= 10;
        length ++;
    }      
    int iter = length;
    for(iter;iter > 0;iter --){
        int divisor = (int)pow(10, iter-1);
        int i = (num / divisor) % 10;
        switch(iter){
            case 4:
            for(i;i>0;i--){
                *r_i = 'M';
                r_i++;
            }
            break;
            default:
            if(i<4){
                 for(i;i>0;i--){
                    *r_i = one[iter];
                    r_i++;
                }   
            }
            else if(i == 4){
                *r_i = one[iter];r_i++;
                *r_i = five[iter];r_i++;
            }
            else if(i == 9){
                *r_i = one[iter];r_i++;
                *r_i = one[iter+1];r_i++;
            }
            else{
                *r_i++ = five[iter];i -= 5;
                for(i;i>0;i--){
                    *r_i = one[iter];
                    r_i++;
                }
            }
        }
    }
    *r_i = '\0';
    return roman;
}