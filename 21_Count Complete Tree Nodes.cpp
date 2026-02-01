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

int lh(TreeNode* root){
    int cnt = 0;
    while(root){
        cnt++;
        root = root->left;
    }
    return cnt;
}

int rh(TreeNode* root){
    int cnt = 0;
    while(root){
        cnt++;
        root = root->right;
    }
    return cnt;
}

int count(TreeNode* root){

    if(root == nullptr) return 0;

    int left  = lh(root->left);
    int right = rh(root->right);

    if(left == right){
        return (1 << (left + 1)) - 1;
    }
    else{
        return 1 + count(root->left) + count(root->right);
    }
}

int countNodes(TreeNode* root) {
    return count(root);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    TreeNode* root = build(n, arr);

    cout << countNodes(root);

    return 0;
}
