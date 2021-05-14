#include<iostream>
/*
二叉搜索树的实现，插入，搜索和删除时间复杂度为O(height),
遍历时间复杂度为O(nodenum)
*/
template<class T>
struct leaf
{
    T key;
    leaf *p;
    leaf *left;
    leaf *right;
    leaf(T x){
        key=x;
        p=NULL;
        left=NULL;
        right=NULL;
    }
    leaf(){
        key=NULL;
        p=NULL;
        left=NULL;
        right=NULL;
    }
};
template<class T>
class binarysearchtree{
    private:
    int nodenum;//结点的数量
    int height;//树的高度
    leaf<T> *root;//根结点
    leaf<T> *minmum (leaf<T>* node)const;//返回最小的结点,时间复杂度为O(height)
    leaf<T> *maxmum (leaf<T>* node)const;//返回最大的结点 时间复杂度为O(height)
    leaf<T> *successor (leaf<T> *x)const;//返回后继结点(中序顺序) 时间复杂度为O(height)
    leaf<T> *predecessor (leaf<T> *x)const;//返回前驱结点(中序顺序) 时间复杂度为O(height)
    leaf<T> *search (const T& key)const;//查找结点 时间复杂度为O(height)
    void transplant(leaf<T> *u,leaf<T> *v);//删除结点的子方法 O(height)
    public:
    leaf<T> *getroot(){return root;}
    void inorder_tree_walk (leaf<T> *node)const;//中序遍历 时间复杂度为O(nodenum)
    void insert(const T& key);//插入结点 时间复杂度为O(height)
    void delnode(const T& key);//删除结点 时间复杂度为O(height)
    int getheight()const{return height;}//获取树的高度
    int getnodenum()const{return nodenum;}//获取结点数
    binarysearchtree();//构造方法
    ~binarysearchtree(){}//析构方法
   


};

