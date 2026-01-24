

// #include <bits/stdc++.h>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// TreeNode* build(int n, vector<int>& arr) {
//     if (n == 0 || arr[0] == -1) return nullptr;

//     queue<TreeNode*> q;
//     TreeNode* root = new TreeNode(arr[0]);
//     q.push(root);

//     int i = 1;
//     while (!q.empty() && i < n) {
//         TreeNode* curr = q.front();
//         q.pop();

//         // left child
//         if (i < n && arr[i] != -1) {
//             curr->left = new TreeNode(arr[i]);
//             q.push(curr->left);
//         }
//         i++;

//         // right child
//         if (i < n && arr[i] != -1) {
//             curr->right = new TreeNode(arr[i]);
//             q.push(curr->right);
//         }
//         i++;
//     }
//     return root;
// }
  
// int maxdepth(TreeNode* root){
//     if(root==nullptr){
//         return 0;
//     }

//     int lh=maxdepth(root->left);
//     int rh=maxdepth(root->right);

//     return 1+max(lh,rh);
// }

// bool balancedbinarytree(TreeNode* root){

//     if(root==nullptr) return true;
//     int left=maxdepth(root->left);
//     int right=maxdepth(root->right);

//     if(abs(left-right)>1) return false;

//     bool lefthalf=balancedbinarytree(root->left);
//     bool righthalf=balancedbinarytree(root->right);
    
//     if(lefthalf==false||righthalf==false) return false;

//     return true;
// }

// int main() {
//     int n;
//     cout << "Enter size of array: ";
//     cin >> n;

//     vector<int> arr(n);
//     cout << "Enter nodes of tree: ";
    
//     for (int i = 0; i < n; i++) cin >> arr[i];
//        TreeNode* root = build(n, arr);
       
//        cout<<balancedbinarytree(root);

//     return 0;
// }



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

int find_height(TreeNode* root) {
    if (root == nullptr) return 0;

    int left = find_height(root->left);
    int right = find_height(root->right);

    if (left == -1 || right == -1) return -1;

    if (abs(left - right) > 1) return -1;

    return 1 + max(left, right);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    TreeNode* root = build(n, arr);

    int num = find_height(root);

    if (num != -1) cout << "true";
    else cout << "false";

    return 0;
}




