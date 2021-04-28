#include<iostream>
//×î´ó¶ÑÅÅÐò 
static int t=1;
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
void heapsort(int *a,int i,int length){
    int l=left(i);
    
    
    int r=right(i);
    int largest;
    
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
        heapsort(a,largest,length);
    }
    


    

    
    


}
void bmheap(int *a,int length){
	for(int i=(length-1)/2;i>=0;i--)
	heapsort(a,i,length);
	
	
}
int main(){
   
   int a[10]={12,17,14,6,13,10,1,5,7,23};
   int length=sizeof(a)/sizeof(a[0]); 
   bmheap(a,length);
   for(int j=0;j<length;j++)
        cout<<a[j]<<"\t";
   
}
