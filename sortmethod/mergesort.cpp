#include<iostream>
/*
归并排序，采用分治的思想，将要排序数组分为各个小的数组，
比较排序，时间复杂度为Θ(nlgn),递归式为T(n)=2T(n/2)+T(n)
*/
void merge(int *a,int p,int q,int r){
    int n1=q-p;//获得左子数组的长度
    int n2=r-q;//获得右子数组的长度
    int *l=new int [n1];
    int *d=new int [n2];
    for(int i=0;i<n1;i++)//传入数据
    l[i]=a[p+i];
    for(int i=0;i<n2;i++)//传入数据
    d[i]=a[q+i];
    int i=0;//左子数组的索引
    int j=0;//右字数组的索引
    int k=p;//排序数组的索引
    
    //通过比较左右两个数组的值,得出排序数组当前索引的值
    while(i<n1&&j<n2){
        if(l[i]<=d[j]){
            a[k]=l[i];
            k++;
            i++;
        }
        else{
           a[k]=d[j];
           k++;
           j++;
        }
    }
    while(i<n1){
        a[k]=l[i];
        k++;
        i++;
    }
    while(j<n2){
        a[k]=d[j];
        k++;
        j++;

    }
    delete []l;
    delete []d;
}
//归并排序，递归方法
void mergesort(int *a,int p,int r){
    if(p<r){
        int q=(p+r)/2;//划分为2
        mergesort(a,p,q);//左划分
        mergesort(a,q+1,r);//右划分
       merge(a,p,q,r);//进行排序
    }
}
int main(){
    using namespace std;
    int a[5]={1,3,2,5,4};
    int r=sizeof(a)/sizeof(a[0])-1;
    mergesort(a,0,r);
    for(int i=0;i<=r;i++)
    cout<<a[i]<<"\t";
}