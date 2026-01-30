


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

 vector<int> rightView(TreeNode* root) {
       queue<pair<TreeNode*,int>>q;
       map<int,int>mp;
       q.push({root,0});
       vector<int>ans;
       if(root==nullptr) return ans;
       while(!q.empty()){

        auto it=q.front();
        q.pop();
        TreeNode* node=it.first;
        int level=it.second;
        

        mp[level]=node->val;
        
        if(node->left){
            q.push({node->left,level+1});
        }
        if(node->right){
            q.push({node->right,level+1});
        }
       }

       for(auto it:mp){
        ans.push_back(it.second);
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

    vector<int>ans= rightView(root);

    return 0;
}
