#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

int main(){
   struct Node* root=new Node(1);
   root->left=new Node(2);
   root->right=new Node(3);

}



//vs code

#include<bits/stdc++.h>
using namespace std;

struct TreeNode{

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(nullptr),right(nullptr){};
};
TreeNode* build(int i,int n,vector<int>&arr){
    if(i>=n||arr[i]==-1) return;
    TreeNode* root=new TreeNode(arr[i]);

    root->left=build(2*i+1,n,arr);
    root->right=build(2*i+2,n,arr);

    return root;
}
int main(){
    int n;
    cout<<"enter the size of array";
    cin>>n;
    vector<int>arr(n);
    cout<<"enter nodes of tree";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    TreeNode* root=build(0,n,arr);
    return 0;
}
