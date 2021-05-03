#include "queue.h"
template<class T>
queue<T>::queue(){
    elements=new T[10];
    maxsize=10;
    head=tail=-1;
}
template<class T>
void queue<T>::enQueue(const T& x){
    if(this->full())
    resize();
    tail=(tail+1)%maxsize;
    elements[tail]=x;
}
template<class T>
T queue<T>::deQueue(){
if(this->empty())
throw "error";
head=(head+1)%maxsize;
return elements[head];
}
template<class T>
T queue<T>::gethead()const{
    if(this->empty())
    throw "error";
    return elements[(front+1)%maxsize];
}
template<class T>
void queue<T>::resize(){
    T *temp=elements;
    data=new T[2*maxsize];
    for(int i=1;i<maxsize;i++)
    data[i]=p[(head+i)%maxsize];
    head=0;
    tail=maxsize-1;
    delete p;

}

