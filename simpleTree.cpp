#include<iostream>
using namespace std;

class Tnode{
   int data;
   Tnode *T_left;
   Tnode *T_right;

   public :
       Tnode(int d){
         data = d;
         T_left=NULL;
         T_right=NULL;
       }
};

///recursive method of buildTree
Tnode *buildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    Tnode *n = new Tnode(data);
    n.T_left = buildTree();
    n.T_right = buildTree();
    return n;
}
