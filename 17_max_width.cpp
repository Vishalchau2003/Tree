




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

  int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = 0;

        while (!q.empty()) {
            int size = q.size();
            int min_index = q.front().second;  // This will help in  normalizing the indices 
            int first, last;

            for (int i = 0; i < size; i++) {
                int curr_index = q.front().second - min_index; // Normalize  the index
                TreeNode* node = q.front().first; q.pop();

                // Set the first and last node indices at this level
                if (i == 0) first = curr_index;
                if (i == size - 1) last = curr_index;

                // Push left and right children with normalized indices
               if(node->left)
                    q.push({node->left,(long long)curr_index*2+1});
                if(node->right)
                    q.push({node->right,(long long)curr_index*2+2});
            }

            ans = max(ans, last - first + 1);  // Calculate the width at this level
        }

        return ans;
    }

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    TreeNode* root = build(n, arr);

    cout<<widthOfBinaryTree(root);

    return 0;
}