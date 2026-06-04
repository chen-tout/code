#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

struct BTNode{
    int data;
    BTNode*left;
    BTNode*right;
    BTNode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
    

};
BTNode*createBTree(vector<int>nodes,int &i){
    if(i>=nodes.size()||nodes[i]==-1){
        i++;
        return NULL;
    }
    BTNode*root=new BTNode(nodes[i]);
    i++;
    root->left=createBTree(nodes,i);
    root->right=createBTree(nodes,i);
    return root;


}
bool find(BTNode* root, int target) {
    if (root == nullptr) return false;
    if (root->data == target) return true;
    return find(root->left, target) || find(root->right, target);
}

BTNode* ancestor(BTNode*root,int m,int n){
    if(root==NULL||root->data==m||root->data==n){
        return root;
    }
   BTNode*left=ancestor(root->left,m,n);
   BTNode*right=ancestor(root->right,m,n);
    if(left!=NULL&&right!=NULL){
        return root;
        
    }
    if(left!=NULL){
        return left;
    }
    else{
        return right;
    }
   


}

int main(){
    int m,n;
    cin>>m>>n;
    cin.ignore();

    string line;
    vector<int>nodes;
    getline(cin,line);
    stringstream ss(line);
    int temp;
    while(ss>>temp){
        nodes.push_back(temp);

    }
    int index=0;
    BTNode*root=createBTree(nodes,index);
    if(!find(root,m)||!find(root,n)){
        cout<<"-1"<<endl;
    }
    else{
        BTNode*ans=ancestor(root,m,n);
        cout<<ans->data;
    }

    return 0;

    

}