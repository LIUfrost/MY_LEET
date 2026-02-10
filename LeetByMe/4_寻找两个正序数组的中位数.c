#include"C:\1.CODE\GIT\MY_LEET\include\common.h"

//def主函数
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int num = (nums1Size + nums2Size) / 2;
    if(nums1Size == 0){     // 边界条件检测
        if((nums1Size + nums2Size)%2 == 0){
            return (double)(nums2[num] + nums2[num - 1]) / 2;
        }
        else{
            return (double)nums2[num];
        }
    }
    if(nums2Size == 0){
        if((nums1Size + nums2Size)%2 == 0){
            return (double)(nums1[num] + nums1[num - 1]) / 2;
        }
        else{
            return (double)nums1[num];
        }
    }
    int *p1, *p2;
    int l1, l2, r1, r2;
    if(nums1[0] <= nums2[0]){
        p1 = nums1;
        l1 = 1;
        l2 = 0;
    }  
    else{
        p1 = nums2;
        l1 = 0;
        l2 = 1;
    }
    if(nums1[nums1Size-1] <= nums2[nums2Size-1]){
        p2 = nums2 + nums2Size - 1;
        r1 = nums1Size - 1;
        r2 = nums2Size - 2;
    }
    else{
        p2 = nums1 + nums1Size - 1;
        r1 = nums1Size - 2;
        r2 = nums2Size - 1;
    }

    for (int i = 0; i < num; i++)
    {
        if(l1 == nums1Size){
            p1 = nums2 + (l2++);
        }
        else if(l2 == nums2Size){
            p1 = nums1 + (l1++);
        }
        else if (nums1[l1] > nums2[l2])
        {
            p1 = nums2 + (l2++);
        }
        else{
            p1 = nums1 + (l1++);
        }

        if(r1 == -1){
            p2 = nums2 + (r2--);
        }
        else if(r2 == -1){
            p2 = nums1 + (r1--);
        }
        else if(nums1[r1] > nums2[r2]){
            p2 = nums1 + (r1--);
        }
        else{
            p2 = nums2 + (r2--);
        }
    }

    return (double)(*p1 + *p2) / 2;
}

//def测试客户端
int main(){
    int nums1[4] = {0,2,6,8};
    int nums2[5] = {0, 5, 8, 34, 76};
    double answer = findMedianSortedArrays(nums1, 4, nums2, 5);
    printf("%lf", answer);
    return 0;
}