#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int c=0;
int s=0;

struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node*root=NULL;


void parentOfNode(struct node*root,int element){
    if(root==NULL){
        return;
    }
    else if(root->left!=NULL&&root->left->data==element||root->right!=NULL&&root->right->data==element){
        cout<<root->data;
    }
    else{
        parentOfNode(root->left,element);
        parentOfNode(root->right,element);
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
    cout<<"Parent Node"<<"   ";
    parentOfNode(root,5);
    return 0;
}
