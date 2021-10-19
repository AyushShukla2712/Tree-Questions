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


void printAllNodesOfGivenLevel(struct node*root,int level){
    if(root==NULL){
        return;
    }
    else{
        if(level==1){
            cout<< root->data<<" ";
        }
        else{
            return (printAllNodesOfGivenLevel(root->left,level-1),printAllNodesOfGivenLevel(root->right,level-1));
        }
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
    
    cout<<"Print All Nodes of Given Level"<<"   ";
    printAllNodesOfGivenLevel(root,3);
    
    return 0;
}
