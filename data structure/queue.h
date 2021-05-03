template<class T>
class queue{
    private:
    T *elements;
    int maxsize;
    int head;
    int tail;
    void resize();
    public:
    queue();
    void enQueue(const T &x);
    T deQueue();
    T gethead()const;
    ~queue(){delete []elements;}
    void clear{head=tail=-1;}
    bool empty()const{return head==tail;}
    bool full() const{return (tail+1)%maxsize==head;}
    int size()const{
        return (tail-head+maxsize)%maxsize;
    }
   
    
    
};