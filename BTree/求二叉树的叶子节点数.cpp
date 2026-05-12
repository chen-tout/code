#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<sstream>

struct BTnode{
    int data;
    BTnode*left;
    BTnode*right;
    BTnode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

    BTnode*CreateBT(vector<int>&nodes,int&i){
        if(i>=nodes.size()||nodes[i]==-1){
            i++;
            return NULL;
        }
        BTnode*root=new BTnode(nodes[i]);
        i++;
        root->left=CreateBT(nodes,i);
        root->right=CreateBT(nodes,i);
        return root;


    }
    int sum(BTnode*root){
       if(root==NULL){
        return 0;

       }
       if(root->left==NULL&&root->right==NULL){
        return 1;
       }
       return sum(root->left)+sum(root->right);
    }

    int main(){
        string line;
        getline(cin,line);
        stringstream ss(line);
        vector<int>nodes;
        int temp;
        while(ss>>temp){
            nodes.push_back(temp);
        }
        int i=0;
        BTnode*root=CreateBT(nodes,i);
        cout<<sum(root);
        return 0;


    }

