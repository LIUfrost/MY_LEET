#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int maxArea(int* height, int heightSize) {
    if(heightSize <= 1){
        return 0;
    }
    int *height_iter = height + 1;
    int height_max = 0;
    while(height_iter < (height+heightSize)){
        int _ = MIN(*height, *height_iter) * (height_iter - height);
        if (_ > height_max){
            height_max = _;
        }
        height_iter++;
    }
    return MAX(height_max, maxArea(height + 1, heightSize - 1));
}