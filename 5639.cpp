#include<iostream>

using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct tree{
    struct node *root;
};
node *makeNode(int n){
    node *tnode = new node;
    tnode->data = n;
    tnode->left = NULL;
    tnode->right = NULL;
    return tnode;
}
void pretotree(node *n,tree *t, node *tmp){
    if(t->root==NULL) t->root = n;
    else{
        if(n->data<tmp->data){
            if(tmp->left==NULL){
                tmp->left = n;
            }
            else{
                pretotree(n,t,tmp->left);
            }
        }
        else{
            if(tmp->right==NULL){
                tmp->right = n;
            }
            else{
                pretotree(n,t,tmp->right);
            }
        }
    }
}
void printpost(node *n){
    if(n!=NULL){
        printpost(n->left);
        printpost(n->right);
        cout<<n->data<<"\n";
    }
}
int main(){    
    
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int n;

    //create tree
    tree *stree = new tree;
    stree->root = NULL;
    while (cin>>n){
        node *m = makeNode(n);
        pretotree(m,stree,stree->root);
    }
    printpost(stree->root);

    return 0;
}
