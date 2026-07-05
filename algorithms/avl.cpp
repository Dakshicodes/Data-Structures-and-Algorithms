#include<iostream>
#include<algorithm>
using namespace std;
typedef struct node{
    int key;
    struct node* left;
    struct node* right;
    int height;
}node;
node* createnode(int key){
    node* new_pointer=new node;
    new_pointer->key=key;
    new_pointer->left=NULL;
    new_pointer->right=NULL;
    new_pointer->height=1;
    return new_pointer;
}
void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
int height(node* pointer){
    if(pointer==NULL){
        return 0;
    }
    return pointer->height;
}
int getbalance(node* pointer){
    if(pointer==NULL){
        return 0;
    }
    return height(pointer->left)-height(pointer->right);
}
node* rightrotate(node* y){                                  
    node* x=y->left;
    node* z=x->right;

    x->right=y;
    y->left=z;

    y->height=1+max(height(y->left),height(y->right));
    x->height=1+max(height(x->left),height(x->right));
    
    return x;   
}
node* leftrotate(node* x){
    node*y=x->right;
    node* z=y->left;

    y->left=x;
    x->right=z;

    x->height=1+max(height(x->left),height(x->right));
    y->height=1+max(height(y->left),height(y->right));

    return y;
}
node* insertavl(node* root_pointer,int key){
    if(root_pointer==NULL){
        root_pointer=createnode(key);
        return root_pointer;
    }
    if(key<root_pointer->key){
        root_pointer->left=insertavl(root_pointer->left,key);
    }
    else if(key>root_pointer->key){
        root_pointer->right=insertavl(root_pointer->right,key);
    }
    else{
        cout<<"no duplicate entries pls"<<endl;
        return root_pointer;
    }
    root_pointer->height=1+max(height(root_pointer->left),height(root_pointer->right));
    int balance_factor=height(root_pointer->left)-height(root_pointer->right);

    if(balance_factor>1&&key<(root_pointer->left->key)){
        return rightrotate(root_pointer);
    }
    if(balance_factor<-1&&key>(root_pointer->right)->key){
        return leftrotate(root_pointer);
    }
    if(balance_factor>1&&key>(root_pointer->left->key)){
        root_pointer->left=leftrotate(root_pointer->left);
        return rightrotate(root_pointer);
    }
    if(balance_factor<-1&&key<(root_pointer->right->key)){
        root_pointer->right=rightrotate(root_pointer->right);
        return leftrotate(root_pointer);
    }

    return root_pointer;
}
node* minvaluenode(node* pointer){
    node* q;
    while(pointer!=NULL){
        q=pointer;
        pointer=pointer->left;
    }
    return q;
}
node* deletion(node* root_pointer,int key){
    if(root_pointer==NULL){
        return root_pointer;
    }
    if(key<root_pointer->key){
        root_pointer->left=deletion(root_pointer->left,key);
    }
    else if(key>root_pointer->key){
        root_pointer->right=deletion(root_pointer->right,key);
    }
    else{
        if(root_pointer->left==NULL){
            node* temp=root_pointer->right;
            delete root_pointer;
            return temp;
        }
        else if(root_pointer->right==NULL){
            node* temp=root_pointer->left;
            delete root_pointer;
            return temp;
        }
        else{
            node* temp=minvaluenode(root_pointer->right);
            root_pointer->key=temp->key;
            root_pointer->right=deletion(root_pointer->right,temp->key);
        }
    }
    if(root_pointer==NULL){
        return root_pointer;
    }
    root_pointer->height=1+max(height(root_pointer->left),height(root_pointer->right));
    int balance_factor=height(root_pointer->left)-height(root_pointer->right);
    if(balance_factor>1&&getbalance(root_pointer->left)>=0){
        return rightrotate(root_pointer);
    }
    if(balance_factor>1&&getbalance(root_pointer->left)<0){
        root_pointer->left=leftrotate(root_pointer->left);
        return rightrotate(root_pointer);
    }
    if(balance_factor<-1&&getbalance(root_pointer->right)<=0){
        return leftrotate(root_pointer);
    }
    if(balance_factor<-1&&getbalance(root_pointer->right)>0){
        root_pointer->right=rightrotate(root_pointer->right);
        return leftrotate(root_pointer);
    }
    return root_pointer;
}
int main() {
    node* root = NULL;

    root = insertavl(root, 10);
    root = insertavl(root, 20);
    root = insertavl(root, 30);
    root = insertavl(root, 40);
    root = insertavl(root, 50);
    root = insertavl(root, 25);

    cout << "Inorder traversal of the constructed AVL tree is:\n";
    inorder(root);
    cout << endl;

    root = deletion(root, 40);

    cout << "Inorder traversal after deletion of 40:\n";
    inorder(root);
    cout << endl;

    return 0;
}
