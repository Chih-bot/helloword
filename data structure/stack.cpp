#include "stack.h"
#include<iostream>
using namespace std;
template<class T>
stack<T>::stack(){
elements=new T[10];
top=-1;
size=10;
}
template<class T>
stack<T>::~stack(){
delete []elements;
top=-1;
}
template<class T>
void stack<T>::push(const T &element){
top++;
if(top>size-1){
    T *temp=new int[size];
    for(int i=0;i<size;i++)
    temp[i]=elements[i];
    size+=10;
delete []elements;
elements=temp;
}
elements[top]=element;


}
template<class T>
void stack<T>::pop(){
    delete elements[top];
    top--;
}
int main(){
    stack <int>s=stack<int>();
    s.push(1);
    s.push(2);
    cout<<s.ptop();
    
}