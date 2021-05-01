#include<iostream>
#include<stdlib.h>

/*快速排序,选择一个主元，把比这元素小的放左边，
大的放右边，然后移动其主元的位置，最后划分出两
个子数组
*/
//划分的方法，时间复杂度为Θ(n)
int partition(int *a,int p,int r){
    int x=a[r];//主元
    int q=p-1;//主元将要换入的位置
    for(int j=p;j<r;j++){
         
         if(a[j]<=x){
             q++;
             int tmp=a[j];
             a[j]=a[q];
             a[q]=tmp;
         }
    }

    a[r]=a[q+1];
    a[q+1]=x;
    return q;
}
/*快速排序，最坏情况：其递归式为T(n)=T(n-1)+Θ(n) 时间复杂度：Θ(n^2)
平衡情况：时间复杂度O(nlgn)
最好情况：T(n)=2T(n/2)+Θ(n) 时间复杂度为:Θ(nlgn)
*/
void quicksort(int *a,int p,int r){
    if(p<r){
        int q=partition(a,p,r);
        quicksort(a,p,q);
        quicksort(a,q+1,r);
    }
}
/*
随机化版本
*/
int randompartition(int *a,int p,int r){
    int i=rand()%(r-p+1)+p;
    int tmp=a[i];
    a[i]=a[r];
    a[r]=tmp;
    return partition(a,p,r);
}
void randomquciksort(int *a,int p,int r){
    if(p<r){
        int q=randompartition(a,p,r);
        randomquciksort(a,p,q);
        randomquciksort(a,q+1,r);
    }
}

int main(){
    using namespace std;
    int a[5]={1,3,2,5,4};
    int r=sizeof(a)/sizeof(a[0])-1;
    randomquciksort(a,0,r);
    for(int i=0;i<=r;i++){
        cout<<a[i]<<"\t";
    }

}
