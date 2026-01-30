




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

        if (i < n && arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==nullptr||root==p||root==q){
        return root;
       }

       TreeNode* left=lowestCommonAncestor(root->left,p,q);
       TreeNode* right=lowestCommonAncestor(root->right,p,q);

       if(left==nullptr) return right;
       else if(right==nullptr) return left;
       else return root;
    }

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    TreeNode* root = build(n, arr);


    return 0;
}