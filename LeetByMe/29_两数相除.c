int divide(int dividend, int divisor) {
    int sign = 1;
    if(divisor*dividend < 0){
        sign = 0;
    }
    dividend = dividend > 0 ? dividend : -dividend;
    divisor = divisor > 0 ? divisor : -divisor;
    int temp = dividend;
    int ans = -1;
    while(dividend >= 0){
        dividend -= divisor;
        ans++;
    }
    ans = sign ? ans : -ans;
    return ans;
}