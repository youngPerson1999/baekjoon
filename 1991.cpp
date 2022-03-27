#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

struct node{
    char data;
    char ldata;
    char rdata;
    struct node *left;
    struct node *right;
};

struct tree{
    struct node *root;
};
vector<pair<char,char> >nodes(26);
node *makeNode(char n,char l, char r){
    node *tnode = new node;
    tnode->data = n;
    tnode->ldata = l;
    tnode->rdata = r;
    tnode->left = NULL;
    tnode->right = NULL;
    return tnode;
}
void insertTree(node *tmp,tree *t){
    if(t->root==NULL) {
        t->root = tmp;
        if(tmp->ldata!='.'){
            char lnode = tmp->ldata;
            tmp->left = makeNode(lnode,nodes[lnode-'A'].first,nodes[lnode-'A'].second);
            insertTree(t->root->left,t);
        }
        if(tmp->rdata!='.') {
            char rnode = tmp->rdata;
            tmp->right = makeNode(rnode,nodes[rnode-'A'].first,nodes[rnode-'A'].second);
            insertTree(t->root->right,t);
        }
    }
    else{
        if(tmp->ldata!='.'){
            char lnode = tmp->ldata;
            tmp->left = makeNode(lnode,nodes[lnode-'A'].first,nodes[lnode-'A'].second);
            insertTree(tmp->left,t);
        }
        if(tmp->rdata!='.'){
            char rnode = tmp->rdata;
            tmp->right = makeNode(rnode,nodes[rnode-'A'].first,nodes[rnode-'A'].second);
            insertTree(tmp->right,t);
        }
    }
}
void printpre(node *n){
    if(n!=NULL){
        cout<<n->data;
        printpre(n->left);
        printpre(n->right);
    }
}
void printin(node *n){
    if(n!=NULL){
        printin(n->left);
        cout<<n->data;
        printin(n->right);
    }
}
void printpost(node *n){
    if(n!=NULL){
        printpost(n->left);
        printpost(n->right);
        cout<<n->data;
    }
}
int main(){    
    
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int n;
    char rt,le,ri;

    //create tree
    tree *stree = new tree;
    stree->root = NULL;

    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>rt>>le>>ri;
        nodes[rt-'A'] = make_pair(le,ri);
    }
    insertTree(makeNode('A',nodes[0].first,nodes[0].second),stree);
    printpre(stree->root);
    cout<<"\n";
    printin(stree->root);
    cout<<"\n";
    printpost(stree->root);

    return 0;
}
