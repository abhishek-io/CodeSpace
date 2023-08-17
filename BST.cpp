#include <iostream>
using namespace std;
#include<queue>
#include<limits.h>
//Structure of binary searct tree
struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

 

//Create new node for insertion
struct BstNode* GetNewNode(int data){
    BstNode* PtrOfNewNode = new BstNode();
    PtrOfNewNode->data = data;
    PtrOfNewNode->left=PtrOfNewNode->right = NULL;
    return PtrOfNewNode;
}

 

//Insert into binary tree
struct BstNode* Insert(BstNode* rootPtr, int data){
    if(rootPtr==NULL){
        rootPtr = GetNewNode(data);
        return rootPtr;
    }
    else if(data<=rootPtr->data){
        rootPtr->left = Insert(rootPtr->left,data);
    }
    else{
        rootPtr->right = Insert(rootPtr->right,data);
    }
}

 

//Search from binary tree
bool Search(BstNode* rootPtr, int data){
    if(rootPtr == NULL){
        return false;
    }
    else if(rootPtr->data == data){
        return true;
    }
    else if(data <= rootPtr->data){
        return Search(rootPtr->left,data);
    }
    else{
        return Search(rootPtr->right,data);
    }
}

 

//find minimum data from binary tree, iterative solution
int findMin(BstNode* root){
    if(root == NULL){
        cout<<"tree is empty"<<endl;
        return -1;
    }
    while(root->left !=NULL){
        root = root->left;
    }
    return root->data;    
}

 

//find minimum data from binary tree, recursive solution
int FindMinRecursive(BstNode* root){
    if(root==NULL){
        cout<<"tree is empty"<<endl;
        return -1;
    }
    else if(root->left == NULL){
        return root->data;
    }
    return FindMinRecursive(root->left);
}

 

//find max data from binary tree, iterative solution
int FindMax(BstNode* root){
    if(root == NULL){
        cout<<"tree is empty"<<endl;
    }
    while(root->right !=NULL){
        root  = root->right;
    }
    return root->data;
}

 

//find max data from bianry tree, recusive solution
int FindMaxRecursive(BstNode* root){
    if(root == NULL){
        cout<<"tree is empty"<<endl;
    }
    else if(root->right == NULL){
        return root->data;
    }
    return FindMaxRecursive(root->right);
}

 

//find height of a tree, recursive solution.
int FindHeight(BstNode* root){
    if(root == NULL)return -1;
    return max(FindHeight(root->left),FindHeight(root->right))+1; 
}

 

void bfsLevelOrderTraversal(BstNode* root){
    if(root==NULL)return;
    queue<BstNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        BstNode* current = Q.front();
        cout<< current->data<<" ";
        if(current->left!=NULL)Q.push(current->left);
        if(current->right!=NULL)Q.push(current->right);
        Q.pop();
    }
}

 

void dfsPreOrderTraversal(BstNode* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    dfsPreOrderTraversal(root->left);
    dfsPreOrderTraversal(root->right);
}
void dfsInOrderTraversal(BstNode* root){
    if(root == NULL)return;
    dfsInOrderTraversal(root->left);
    cout<<root->data<<" ";
    dfsInOrderTraversal(root->right);
}
void dfsPostOrderTraversal(BstNode* root){
    if(root == NULL)return;
    dfsPostOrderTraversal(root->left);
    dfsPostOrderTraversal(root->right);
    cout<<root->data<<" ";
}
bool IsSubTreeLesser(BstNode* root,int data){
    if(root==NULL)return true;
    if(root->data<=data
&& IsSubTreeLesser(root->left,data)
&& IsSubTreeLesser(root->right,data))
        return true;
    else
        return false;
}
bool IsSubTreeGreater(BstNode* root,int data){
    if(root==NULL)return true;
    if(root->data>data
&& IsSubTreeGreater(root->left,data)
&& IsSubTreeGreater(root->right,data))
        return true;
    else
        return false;
}
bool IsBinarySearchTree(BstNode* root){
    if(root==NULL)return true;
    if(IsSubTreeLesser(root->left,root->data)
&&IsSubTreeGreater(root->right,root->data)
&& IsBinarySearchTree(root->left)
&& IsBinarySearchTree(root->right))
        return true;
    else
        return false;
}
bool IsBinarySearchTreeUtil(BstNode* root, int MinVal, int MaxVal){
    if(root==NULL)return true;
    if( root->data > MinVal && root->data < MaxVal 
&& IsBinarySearchTreeUtil(root->left, MinVal, root->data)
&& IsBinarySearchTreeUtil(root->right, root->data, MaxVal))
        return true;
    else
        return false;
}
bool IsBinarySearchTree2(BstNode* root){
    return IsBinarySearchTreeUtil(root, INT_MIN, INT_MAX);
}
//main function
int main() {
    BstNode* root = NULL;
    root = Insert(root,5);  
    root = Insert(root,6);
    root = Insert(root,4);
    root = Insert(root,2);
    root = Insert(root,3);
    root = Insert(root,7);

    if(IsBinarySearchTree(root)) cout<<"your tree is Binary Search Tree"<<endl;
    else cout<< "your tree is Not Binary Search Tree"<<endl;

    if(IsBinarySearchTree2(root)) cout<<"your tree is Binary Search Tree"<<endl;
    else cout<< "your tree is Not Binary Search Tree"<<endl;

    cout<<"BreadthFirstSearch - levelOrderTraversal of your tree is: ";
    bfsLevelOrderTraversal(root);
    cout<<endl;

    cout<<"DepthFirstSearch - PreOrderTraversal of your tree is: ";
    dfsPreOrderTraversal(root);
    cout<<endl;

    cout<<"DepthFirstSearch - InOrderTraversal of your tree is: ";
    dfsInOrderTraversal(root);
    cout<<endl;

    cout<<"DepthFirstSearch - PostOrderTraversal of your tree is: ";
    dfsPostOrderTraversal(root);
    cout<<endl;

    int search = 10;
    bool searchRes = Search(root,search);
    if(searchRes) cout<<"search value "<<search<<" is found"<<endl;
    else cout<<"search value "<<search<<" is not found"<<endl;

    int height= FindHeight(root);
    cout<<"height of tree is: "<<height<<endl;

	int mindata = findMin(root);
	cout<<"min value in tree: "<<mindata<<endl;

	int mindatarec  = FindMinRecursive(root);
	cout<<"min value in tree recursively is: "<<mindatarec<<endl;

	int maxdata = FindMax(root);
	cout<<"max value in tree is: "<<maxdata<<endl;

	int maxdatarec = FindMaxRecursive(root);
	cout<<"max value in tree recursively is: "<<maxdatarec<<endl;

}
