#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    int hd;
    struct node*left;
    struct node*right;
};
struct node*root=NULL;

void bottomView(struct node*root){
    if(root==NULL){
        return;
    }
    int hd=0;
    map<int,int>m;
    queue<struct node *>q;
    root->hd=hd;
    q.push(root);
    while(!q.empty()){
        struct node*temp=q.front();
        q.pop();
        hd=temp->hd;
        m[hd]=temp->data;
        if(temp->left!=NULL){
            temp->left->hd=hd-1;
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            temp->right->hd=hd+1;
            q.push(temp->right);
        }
    }
    map<int,int>::iterator i;
    for(i=m.begin();i!=m.end();++i){
        cout<<i->second<<" ";
    }
}


void insert(struct node*newnode){
    if(root==NULL){
        root=newnode;
    }
    else{
        queue<struct node*>q;
        q.push(root);
        while(!q.empty()){
            struct node *temp=q.front();
            q.pop();
            if(temp->left==NULL){
                temp->left=newnode;
                break;
            }
            else{
                q.push(temp->left);
            }
            if(temp->right==NULL){
                temp->right=newnode; 
                break;
            }
            else{
                q.push(temp->right);
            }
        }
        
    }
    
}



void create(){
    int data;
    struct node *newnode;
    cout<<"Enter Data you want to insert"<<endl;
    cin>>data;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->hd=0;
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    insert(newnode);
    
}

int main(){
    create();
    create();
    create();
    create();
    create();
    create();
    create();
    cout<<"Bottom View"<<"  ";
    bottomView(root);
    return 0;
}
