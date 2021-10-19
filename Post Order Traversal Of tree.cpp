#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node*root=NULL;

void displaypostorder(struct node*root)
{
    if (root == NULL)
        return;
    else{
        
    displaypostorder(root->left);
    displaypostorder(root->right);
    cout << root->data << ' ';
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
    cout<<"PostOrder"<<"   ";
    displaypreorder(root);
    return 0;
}
