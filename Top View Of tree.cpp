#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node*root=NULL;


void LeftOfTree(struct node*l){
    if(l==NULL){
        return;
    }
    else{
        LeftOfTree(l->left);
        cout<<l->data<<" ";
    }
}
void RightOfTree(struct node*r){
    if(r==NULL){
        return;
    }
    else{
        cout<<r->data<<" ";
        RightOfTree(r->right);
    }
}


void printTopViewOfTree(struct node*root){
    if(root==NULL){
        return;
    }
    
    
        LeftOfTree(root->left);
        cout<<root->data<<" ";
        RightOfTree(root->right);
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
    cout<<"Top View"<<"  ";
    printTopViewOfTree(root);
    return 0;
}
