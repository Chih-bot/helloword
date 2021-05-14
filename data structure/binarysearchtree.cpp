#include "binarysearchtree.h"
#include<cmath>
using namespace std;
template<class T>
binarysearchtree<T>::binarysearchtree(){
    root=NULL;
    nodenum=1;
    height=0;
}
/*先从根结点的值比较。根据二叉搜索树的性质，
插入结点比当前结点小的往左子树插入,大的往右子
树插入。若树为空则直接，插入到根结点
*/
template<class T>
void binarysearchtree<T>::insert(const T& key){
    leaf<T> *node=new leaf<T>(key);
    
    leaf<T> *y=NULL;
    leaf<T> *x=root;
    while(x!=NULL){
        y=x;
        if(node->key<x->key)
        x=x->left;
        else
        x=x->right;
    }
    node->p=y;
    if(y==NULL)
    root=node;
    else if(node->key<y->key)
    y->left=node;
    else
    y->right=node;
    nodenum++;
    height=(int)log2(nodenum);
    

}
/*
根据性质最大结点在其右子树
*/
template<class T>
leaf<T> *binarysearchtree<T>::maxmum(leaf<T>* node)const{
while(node->right!=NULL)
node=node->right;
return node;


}
/*
根据性质最小结点在其左子树
*/
template<class T>
leaf<T> *binarysearchtree<T>::minmum(leaf<T>* node)const{
    
    while(node->left!=NULL)
    node=node->left;
   return node;
}
template<class T>
leaf<T> *binarysearchtree<T>::successor(leaf<T> *x)const{
leaf<T> *node=x;
if(node->right!=NULL)
return minmum(node->right);
leaf<T> *y=node->p;
while (y!=NULL&&node==y->right){
    node=y;
    y=y->p;
}
return y;
}
template<class T>
leaf<T> *binarysearchtree<T>::predecessor(leaf<T> *x)const{
    leaf<T> *node=x;
    if(node->left!=NULL)
    return maxmum(node->left);
    leaf<T> *y=node->p;
    while(y!=NULL&&node==y->left){
        node=y;
        y=y->p;
    }
    return y;
}
template<class T>
leaf<T>* binarysearchtree<T>::search (const T& key)const{
leaf<T> *node=root;
while(node!=NULL){
    if(node->key==key)
    return node;
    else if(node->key>key)
    node=node->left;
    else
    node=node->right;
}
return NULL;
}
/*
删除结点的子方法
*/
template<class T>
void binarysearchtree<T>::transplant(leaf<T> *u,leaf<T> *v){
    if(u->p==NULL)
    root=v;
    else if(u==u->p->left)
    u->p->left=v;
    else
    u->p->right=v;
    if(v!=NULL)
    v->p=u->p;
    
}
/*
分三种情况删除
1.左子树为空，直接将右子树替换掉父结点
2.右子树为空，直接将左子树替换掉父结点
3.左右子树均有结点，使用被删除结点的后继结点替换，
而根据二叉搜索树性质，其后继结点无左结点。而这种
情况又有两种情况
(1)当后继结点父节点为被删除结点时，则后继结点直接替换掉被删除
结点。
(2)当后继结点父节点不是为被删除结点时，则后继结点的位置先被其右节点替换，
被删除结点的右结点的父节点改为后继结点，最后替换被删除结点
finally
delete node;
*/
template<class T>
void binarysearchtree<T>::delnode(const T& key){
    leaf <T>* node=search(key);
    if(node==NULL)
    return ;
    if(node->left==NULL)
    transplant(node,node->right);
    else if(node->right==NULL)
    transplant(node,node->left);
    else{
    leaf<T> *y=minmum(node->right);
    if(y->p!=node){
        transplant(y,y->right);
        y->right=node->right;
        y->right->p=y;
    }
    transplant(node,y);
    y->left=node->left;
    y->left->p=y;
    }
    delete node;
    nodenum--;
    int height=(int)log2(nodenum);
    
}
/*
中序遍历
*/
template<class T>
void binarysearchtree<T>::inorder_tree_walk(leaf<T> *node)const{
    if(node!=NULL){
        inorder_tree_walk(node->left);
        cout<<node->key<<"\t";
        inorder_tree_walk(node->right);
    }
}

int main(){
    binarysearchtree<int> t=binarysearchtree<int>();
    int a=0;
    t.insert(6);
    t.insert(5);
    t.insert(5);
    t.insert(8);
    t.insert(2);
    t.insert(7);
    t.delnode(6);
    t.inorder_tree_walk(t.getroot());
   
}

