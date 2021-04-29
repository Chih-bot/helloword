#include<iostream>
//堆排序

 using namespace std;
int parent(int i){
    return i-1/2;
}
int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*(i+1);
}
//此方法维护最大堆的性质,时间复杂度为O(lgn)
void heap(int *a,int i,int length){
    //获取左右子节点
    int l=left(i);
    int r=right(i);
    
    int largest;//最大值的索引
    
    if (l<length&&a[l]>a[i])
        largest=l;
    else
    largest=i;
     if(r<length&&a[r]>a[largest])
    largest=r;
    if(largest!=i){
        int tmp= a[i];
        a[i]=a[largest];
        a[largest]=tmp;
        heap(a,largest,length);//此处可用循环式重写
    }
    
}
//最大堆的建成,时间复杂度为O(n)
void bmheap(int *a,int length){
	for(int i=(length-1)/2;i>=0;i--)//在索引length/2，length/2+1...n的节点为叶节点
	heap(a,i,length);
	}
//堆排序,时间复杂度为O(nlgn)
    void heapsort(int *a,int length){
	bmheap(a,length);
	int size=length;
	for(int i=length-1;i>=1;i--){
		int tmp=a[i];
		a[i]=a[0];
		a[0]=tmp;
		size--;
		heap(a,0,size);
	}
}
int main(){
   
   int a[10]={12,17,14,6,13,10,1,5,7,23};
   int length=sizeof(a)/sizeof(a[0]); 
   heapsort(a,length);
   for(int j=0;j<length;j++)
        cout<<a[j]<<"\t";
   
}
