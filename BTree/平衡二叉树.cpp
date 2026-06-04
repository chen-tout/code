#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

// 二叉树节点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 自底向上计算高度，如果不平衡则返回 -1
int checkHeight(TreeNode* node) {
    if (node == NULL) return 0;
    
    int leftHeight = checkHeight(node->left);
    if (leftHeight == -1) return -1;
    
    int rightHeight = checkHeight(node->right);
    if (rightHeight == -1) return -1;
    
    if (abs(leftHeight - rightHeight) > 1) return -1;
    
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

// 层次遍历序列构建二叉树
TreeNode* buildTree(const vector<string>& values) {
    if (values.empty() || values[0] == "null") return NULL;
    
    TreeNode* root = new TreeNode(stoi(values[0]));
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* node = q.front();
        q.pop();
        
        // 构建左子节点
        if (i < values.size() && values[i] != "null") {
            node->left = new TreeNode(stoi(values[i]));
            q.push(node->left);
        }
        i++;
        
        // 构建右子节点
        if (i < values.size() && values[i] != "null") {
            node->right = new TreeNode(stoi(values[i]));
            q.push(node->right);
        }
        i++;
    }
    return root;
}

int main() {
    ifstream infile("in.txt");
    ofstream outfile("out.txt");
    
    if (!infile.is_open()) {
        cerr << "无法打开 in.txt 文件" << endl;
        return 1;
    }
    
    vector<string> values;
    string val;
    // 按空格读取所有节点字符串
    while (infile >> val) {
        values.push_back(val);
    }
    
    TreeNode* root = buildTree(values);
    bool balanced = isBalanced(root);
    
    if (balanced) {
        outfile << "True";
    } else {
        outfile << "False";
    }
    
    infile.close();
    outfile.close();
    
    return 0;
}