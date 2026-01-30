




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


//     int check(Node* root){
//         if(root == nullptr) return 0;

//         if(root->left == nullptr && root->right == nullptr)
//             return root->data;

//         int left = check(root->left);
//         if(left == -1) return -1;

//         int right = check(root->right);
//         if(right == -1) return -1;

//         if(left + right != root->data) return -1;

//         return root->data;   //
//     }

//     bool isSumProperty(Node *root) {
//         if(root == nullptr) return true;
//         return check(root) != -1;
//     }



    bool isSumProperty(TreeNode *root) {

        if(root == nullptr) return true;
        if(root->left == nullptr && root->right == nullptr) return true;

        int left = 0;
        int right = 0;

        if(root->left){
            left = root->left->val;
        }
        if(root->right){
            right = root->right->val;
        }

        if(left + right != root->val){
            return false;
        }

        return isSumProperty(root->left) && isSumProperty(root->right);
    }


int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    TreeNode* root = build(n, arr);

    cout<<isSumProperty(root);

    return 0;
}