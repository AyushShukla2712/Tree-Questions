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



void printSiblingOfGivenElement(struct node*root,int element){
    if(root==NULL){
        return;
    }
    else if(root->left!=NULL&&root->left->data==element&&root->right!=NULL){
        cout<<root->right->data;
    }
    else if(root->right!=NULL&&root->right->data==element&&root->left!=NULL){
        cout<<root->left->data;
    }
    
        printSiblingOfGivenElement(root->left,element);
        printSiblingOfGivenElement(root->right,element);
    
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
    
    cout<<"Sibling Of Given Node"<<"  ";
    printSiblingOfGivenElement(root,5);
    return 0;
}
