template<class T>
class stack{
    private:
    T *elements;
    int top;
    int size;
    public:
    stack();
    ~stack();
    void push( const T &element);
     bool empty() const{return top==-1;}
    void pop();
      T ptop()const {
         return elements[top];}
    
};