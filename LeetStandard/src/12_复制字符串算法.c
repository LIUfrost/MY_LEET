const int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
const char* abc[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

char* intToRoman(int num) {
    char* roman = malloc(sizeof(char)*16);  // 最高为3888，一共15位
    roman[0]='\0';
    for(int i=0;i<13;i++){
        while(num>=values[i]){
            num-=values[i];
            strcpy(roman+strlen(roman),abc[i]);// 重要！将新罗马数字复制到字符串后面
        }
        if(num==0)
        break;
    }
    return roman;
}