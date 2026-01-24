

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(int n, vector<int>& arr) {
    if (n == 0 || arr[0] == -1) return nullptr;

    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n) {
        TreeNode* curr = q.front();
        q.pop();

        // left child
        if (i < n && arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        // right child
        if (i < n && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
  
int maxdepth(TreeNode* root){
    if(root==nullptr){
        return 0;
    }

    int lh=maxdepth(root->left);
    int rh=maxdepth(root->right);

    return 1+max(lh,rh);
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter nodes of tree: ";
    
    for (int i = 0; i < n; i++) cin >> arr[i];
       TreeNode* root = build(n, arr);
       
       cout<<maxdepth(root);

    return 0;
}
