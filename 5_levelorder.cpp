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

void levelorder(TreeNode* root){
    if(root == NULL) return;

    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int sz = q.size();
        vector<int> temp;

        for(int i = 0; i < sz; i++){
            TreeNode* node = q.front();
            q.pop(); 
            temp.push_back(node->val);

            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
        }

        ans.push_back(temp);
    }
}


int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter nodes of tree: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    // TreeNode* root = build(0, n, arr);
       TreeNode* root = build(n, arr);

       levelorder(root);

    return 0;
}