




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

     bool check(TreeNode* r1, TreeNode* r2){
        if(r1 == nullptr || r2 == nullptr){
            return r1 == r2;
        }

        return (r1->val == r2->val) &&
               check(r1->left, r2->right) &&
               check(r1->right, r2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return check(root->left, root->right);
    }

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    TreeNode* root = build(n, arr);

    cout<<isSymmetric(root);

    return 0;
}
