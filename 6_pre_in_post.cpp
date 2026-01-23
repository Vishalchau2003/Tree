

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
  vector<vector<int>> preinpost(TreeNode* root) {
        if (root == nullptr) {
            return {{}, {}, {}};  // return empty pre, in, post
        }

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        vector<int> pre, ino, post;

        while (!st.empty()) {
            auto it = st.top();
            st.pop();

            if (it.second == 1) {
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);
                if (it.first->left != nullptr) {
                    st.push({it.first->left, 1});
                }
            }
            else if (it.second == 2) {
                ino.push_back(it.first->val);
                it.second++;
                st.push(it);
                if (it.first->right != nullptr) {
                    st.push({it.first->right, 1});
                }
            }
            else {
                post.push_back(it.first->val);
            }
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

    
    vector<vector<int>>ans=preinpost(root);
    return 0;
}
