#include<iostream>
void merge(int *a,int p,int q,int r){
    int n1=q-p;
    int n2=r-q;
    int *l=new int [n1];
    int *d=new int [n2];
    for(int i=0;i<n1;i++)
    l[i]=a[p+i];
    for(int i=0;i<n2;i++)
    d[i]=a[q+i];
    int i=0;
    int j=0;
    int k=p;
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
void mergesort(int *a,int p,int r){
    if(p<r){
        int q=(p+r)/2;
        mergesort(a,p,q);
        mergesort(a,q+1,r);
       merge(a,p,q,r);
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