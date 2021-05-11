#include<iostream>
using namespace std;
/*
二分插入排序法,时间复杂度为O(n^2)
*/
void bsort(int *a,int length){
    for(int i=1;i<length;i++){
        int l=0;//左边界
        int r=i-1;//右边界
        int m=-1;//中间指针
        int temp=a[i];//待插入值
        while(l<=r){
            m=(l+r)/2;//求中间指针
            if(a[m]<temp)
            l=m+1;
            else
            r=m-1;
            /*
            移动左右边界，当插入值比中间值大时，则左边界移位动中值下一位，
            而小或的等于时，移动到中间值前一位。
            */
        }
        /*
        移动数值
        */
        for(int j=i-1;j>=l;j--)
        a[j+1]=a[j];
        if(l!=i)
        a[l]=temp;//插入到l位置
    }
}
int main(){
    int a[5]={1,4,5,3,2};
    bsort(a,5);
    for(int i=0;i<5;i++)
    cout<<a[i]<<"\t";

}