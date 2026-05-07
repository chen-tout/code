#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

struct BTNode{
    int data;
    BTNode*lchild;
    BTNode*rchild;
    BTNode(int val){
        data=val;
        lchild=NULL;
        rchild=NULL;
    }
};

BTNode*createBTree(vector<int>&nodes,int&i){
    if(i>=nodes.size()||nodes[i]==-1){
        i++;
        return NULL;
    }
    BTNode*root=new BTNode(nodes[i]);
    i++;
    root->lchild=createBTree(nodes,i);
    root->rchild=createBTree(nodes,i);
    return root;


}
bool match(BTNode*root1,BTNode*root2){
    if(root1==NULL&&root2==NULL){
        return true;
    }
    if(root1==NULL||root2==NULL){
        return false;
    }
    if(root1->data!=root2->data){return false;}
    return match(root1->lchild,root2->lchild)&& match(root1->rchild,root2->rchild);

}


int main(){
string str1,str2;
vector<int>nodes1,nodes2;
getline(cin,str1);
getline(cin,str2);
stringstream s1(str1),s2(str2);
int temp1,temp2;
cout<<"ÇëÊäÈëÊý¾Ý";

while(s1>>temp1){
    nodes1.push_back(temp1);
}
while(s2>>temp2){
    nodes2.push_back(temp2);
}
int index1=0;
int index2=0;
BTNode*root1=createBTree(nodes1,index1);
BTNode*root2=createBTree(nodes2,index2);
if(match(root1,root2)){
    cout<<"YES";

}
else{cout<<"NO";}
return 0;
}