#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* build(int n, vector<int>& arr) {
    if (n == 0 || arr[0] == -1) return nullptr;

    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n) {
        Node* curr = q.front();
        q.pop();

        if (i < n && arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void find_parent(Node* root, unordered_map<Node*, Node*>& parent) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        if (node->left) {
            parent[node->left] = node;
            q.push(node->left);
        }
        if (node->right) {
            parent[node->right] = node;
            q.push(node->right);
        }
    }
}

Node* getTargetNode(Node* root, int target) {
    if (!root) return nullptr;

    if (root->data == target) return root;

    Node* left = getTargetNode(root->left, target);
    if (left) return left;

    return getTargetNode(root->right, target);
}

int minTime(Node* root, int target) {

    unordered_map<Node*, Node*> parent;
    find_parent(root, parent);

    Node* targetNode = getTargetNode(root, target);
    if (targetNode == nullptr) return 0;

    unordered_map<Node*, bool> visited;
    queue<Node*> q;

    q.push(targetNode);
    visited[targetNode] = true;

    int cnt = 0;

    while (!q.empty()) {
        int sz = q.size();
        bool burned = false;

        for (int i = 0; i < sz; i++) {
            Node* node = q.front();
            q.pop();

            if (node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left] = true;
                burned = true;
            }

            if (node->right && !visited[node->right]) {
                q.push(node->right);
                visited[node->right] = true;
                burned = true;
            }

            if (parent[node] && !visited[parent[node]]) {
                q.push(parent[node]);
                visited[parent[node]] = true;
                burned = true;
            }
        }

        if (burned) cnt++;
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node* root = build(n, arr);

    cout << minTime(root, k);

    return 0;
}
