#include<iostream>
#include<vector>
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
BTNode*createBTree(vector<int>&pre,int prestart,vector<int>&ins,int instart,int n){
    if(n<=0){return NULL;}
    int rootval=pre[prestart];
    BTNode*root=new BTNode(rootval);
    int p=instart;
    while(ins[p]!=rootval){
        p++;
    }
    int k=p-instart;
    root->left=createBTree(pre,prestart+1,ins,instart,k);
    root->right=createBTree(pre,prestart+k+1,ins,p+1,n-k-1);
    return root;




} 

void postOrder(BTNode*root){
    if(root==NULL){return;}
    postOrder(root->left);

    postOrder(root->right);
    cout<<root->data<<" ";
}


int main(){
    int n;
    cin>>n;
    vector<int>pre(n),ins(n);
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    for(int i=0;i<n;i++){
        cin>>ins[i];
    }
    BTNode*root=createBTree(pre,0,ins,0,n);
    postOrder(root);
    return 0;

}