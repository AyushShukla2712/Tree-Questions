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



int sumOfLeafNodes(struct node*root){
    if(root==NULL){
        return 0;
    }
    else if(root->left==NULL&&root->right==NULL){
        return s+root->data;
    }
    
    return sumOfLeafNodes(root->left)+sumOfLeafNodes(root->right);
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
    
    cout<<"Sum Of Leaf Nodes"<<"   ";
    cout<<sumOfLeafNodes(root);*/
    return 0;
}
