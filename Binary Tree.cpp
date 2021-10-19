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

void displaypreorder(struct node*root)
{
    if (root == NULL)
        return;
    else{
        cout << root->data << ' ';
    displaypreorder(root->left);
    displaypreorder(root->right);
    }
}
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
void displayinorder(struct node*root)
{
    if (root == NULL)
        return;
    else{
    displayinorder(root->left);
    cout << root->data << ' ';
    displayinorder(root->right);
    }
}

void displayLevelOrder(struct node*root){
    if(root==NULL){
        return;
    }
    else{
        queue<struct node*>t;
        t.push(root);
        while(!t.empty()){
            struct node *temp=t.front();
            cout<<temp->data<<" ";
            t.pop();
            if(temp->left!=NULL){
                t.push(temp->left);
            }
            if(temp->right!=NULL){
                t.push(temp->right);
            }
        
        }
    }
}
int heightofBinaryTree(struct node*root){
    int lheight,rheight;
    if(root==NULL){
        return -1;
    }
    lheight=heightofBinaryTree(root->left);
    rheight=heightofBinaryTree(root->right);
    if(lheight>rheight){
        return lheight+1;
    }
    else{
        return rheight+1;
    }
}

int sumOfNodes(struct node*root){
    if(root==NULL){
        return 0;
    }
    return root->data+sumOfNodes(root->left)+sumOfNodes(root->right);
}

int countNoOFNodes(struct node*root){
    if(root==NULL){
        return 0;
    }
    return 1+countNoOFNodes(root->left)+countNoOFNodes(root->right);
}

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
int countNoNodesOfGivenLevel(struct node*root,int level){
    if(root==NULL){
        return 0;
    }
    else{
        if(level==1){
            c=c+1;;
        }
        else{
            countNoNodesOfGivenLevel(root->left,level-1);
            countNoNodesOfGivenLevel(root->right,level-1);
        }
    }
    return c;
    
}

void leafNodes(struct node*root){
    if(root==NULL){
        return;
    }
    else if(root->left==NULL&&root->right==NULL){
        cout<<root->data<<" ";
    }
    else{
        leafNodes(root->left);
        leafNodes(root->right);
    }
}

int sumOfLeafNodes(struct node*root){
    if(root==NULL){
        return 0;
    }
    else if(root->left==NULL&&root->right==NULL){
        return s+root->data;
    }
    
    return sumOfLeafNodes(root->left)+sumOfLeafNodes(root->right);
}

void mirrorTree(struct node*root){
    if(root==NULL){
        return;
    }
    
    mirrorTree(root->left);
    mirrorTree(root->right);
    swap(root->left,root->right);
}

void deleteTree(struct node*root){
    if(root==NULL){
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    root->left=NULL;
    root->right=NULL;
}

void searchLevelOfGivenElement(struct node*root,int element,int level){
    if(root==NULL){
        return;
    }
    if(root->data==element)
        cout<<level;
        searchLevelOfGivenElement(root->left,element,level+1);
        searchLevelOfGivenElement(root->right,element,level+1);
    
}

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
    /*cout<<"Preorder"<<"   ";
    displaypreorder(root);
    cout<<"Postorder"<<"   ";
    displaypostorder(root);
    cout<<"Inorder"<<"   ";
    displayinorder(root);
    cout<<"Levelorder"<<"   ";
    displayLevelOrder(root);
    cout<<endl;
    cout<<"Height of Tree"<<"   ";
    cout<<heightofBinaryTree(root);
    cout<<endl;
    cout<<"Sum Of All Nodes"<<"   ";
    cout<<sumOfNodes(root);
    cout<<endl;
    cout<<"Count No. Of Nodes"<<"   ";
    cout<<countNoOFNodes(root);
    cout<<endl;
    cout<<"Print All Nodes of Given Level"<<"   ";
    printAllNodesOfGivenLevel(root,3);
    cout<<endl;
    cout<<"Count no of Nodes of Given Level"<<"   ";
    cout<<countNoNodesOfGivenLevel(root,3);
    cout<<endl;
    cout<<"Leaf Nodes"<<"   ";
    leafNodes(root);
    cout<<endl;
    cout<<"Mirror Tree"<<"   ";
    mirrorTree(root);
    displaypreorder(root);
    cout<<endl;
    cout<<"Tree Deleted"<<"   ";
    deleteTree(root);
    root=NULL;
    displaypreorder(root);
    cout<<endl;
    cout<<"Level of Given Element"<<"   ";
    searchLevelOfGivenElement(root,4,0);
    cout<<"Sibling Of Given Node"<<"  ";
    printSiblingOfGivenElement(root,5);
    cout<<"Parent Node"<<"   ";
    parentOfNode(root,5);
    cout<<"Sum Of Leaf Nodes"<<"   ";
    cout<<sumOfLeafNodes(root);*/
    cout<<"Top View"<<"  ";
    printTopViewOfTree(root);
    return 0;
}
