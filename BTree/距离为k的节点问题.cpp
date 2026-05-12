#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <fstream>

using namespace std;

// 二叉树节点结构
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// --- 工具函数：解析 [1,2,#] 格式并建树 ---
TreeNode* buildTree(string str, int targetVal, TreeNode* &targetNode) {
    if (str == "[]" || str.empty()) return nullptr;
    // 去掉前后的 [ ]
    if (str.front() == '[') str = str.substr(1, str.size() - 2);
    
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    if (tokens.empty() || tokens[0] == "#") return nullptr;

    TreeNode* root = new TreeNode(stoi(tokens[0]));
    if (root->val == targetVal) targetNode = root;
    
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < tokens.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // 左孩子
        if (i < tokens.size() && tokens[i] != "#") {
            curr->left = new TreeNode(stoi(tokens[i]));
            if (curr->left->val == targetVal) targetNode = curr->left;
            q.push(curr->left);
        }
        i++;
        // 右孩子
        if (i < tokens.size() && tokens[i] != "#") {
            curr->right = new TreeNode(stoi(tokens[i]));
            if (curr->right->val == targetVal) targetNode = curr->right;
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

class Solution {
    unordered_map<TreeNode*, TreeNode*> parents;
    void findParents(TreeNode* node) {
        if (!node) return;
        if (node->left) { parents[node->left] = node; findParents(node->left); }
        if (node->right) { parents[node->right] = node; findParents(node->right); }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!target) return {};
        findParents(root);

        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited = {target};

        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            if (dist == k) {
                vector<int> res;
                while(size--) { res.push_back(q.front()->val); q.pop(); }
                return res;
            }
            while (size--) {
                TreeNode* curr = q.front(); q.pop();
                // 顺序：左 -> 右 -> 父 (尽量贴合题目要求的输出顺序)
                if (curr->left && !visited.count(curr->left)) {
                    visited.insert(curr->left); q.push(curr->left);
                }
                if (curr->right && !visited.count(curr->right)) {
                    visited.insert(curr->right); q.push(curr->right);
                }
                if (parents.count(curr) && !visited.count(parents[curr])) {
                    visited.insert(parents[curr]); q.push(parents[curr]);
                }
            }
            dist++;
        }
        return {};
    }
};

int main() {
    // 指定从 in.txt 读取
    ifstream infile("in.txt");
    if (!infile) {
        cerr << "无法打开 in.txt" << endl;
        return 1;
    }

    string line1;
    int targetVal, k;

    if (getline(infile, line1) && infile >> targetVal >> k) {
        TreeNode* targetNode = nullptr;
        TreeNode* root = buildTree(line1, targetVal, targetNode);

        Solution sol;
        vector<int> result = sol.distanceK(root, targetNode, k);

        // 严格按照题目要求的 [a,b,c] 格式输出
        cout << "[";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << (i == result.size() - 1 ? "" : ",");
        }
        cout << "]" << endl;
    }

    infile.close();
    return 0;
}