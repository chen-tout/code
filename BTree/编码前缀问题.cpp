#include <iostream>
#include <string>
#include <cstdio>  // 为了使用 freopen

using namespace std;


struct Node {
    Node* children[2];
    bool isEnd;        

    Node() {
        children[0] = nullptr;
        children[1] = nullptr;
        isEnd = false;
    }
};


bool insertAndCheck(Node* root, string s) {
    Node* p = root;
    bool isNewNodeCreated = false; 

    for (int i = 0; i < s.length(); i++) {
        int bit = s[i] - '0'; 
        if (p->isEnd) return false;

        
        if (p->children[bit] == nullptr) {
            p->children[bit] = new Node();
            isNewNodeCreated = true;
        }
        
        
        p = p->children[bit];
    }

   
    if (!isNewNodeCreated) return false;

    // 到达终点，插上结束红旗
    p->isEnd = true;
    return true;
}


void deleteTrie(Node* root) {
    if (root == nullptr) return;
    deleteTrie(root->children[0]);
    deleteTrie(root->children[1]);
    delete root;
}

int main() {
    // 【文件重定向】
    // 将标准输入重定向到 in.txt，这样 cin 就会从文件读取
    freopen("in.txt", "r", stdin);

    string s;
    Node* root = new Node();
    bool possible = true;

    // 【循环读取】
    // 只要读到的字符串不是 "9"，就一直处理
    while (cin >> s && s != "9") {
        if (possible) {
            // 如果某一次插入返回 false，标记为不可立即解码
            if (!insertAndCheck(root, s)) {
                possible = false;
            }
        }
    }

    
    if (possible) {
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }

  
    deleteTrie(root);

    return 0;
}