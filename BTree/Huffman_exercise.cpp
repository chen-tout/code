#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

struct HTNode{  
    double weight;
    int parent,lchild,rchild;
  
    HTNode(double w=0){
        weight=w;
        parent=lchild=rchild=-1;

    }
};
struct HeapNode{ 
    double w;
   int id;
    bool operator>(const HeapNode&s)const{
        return w>s.w;
    }

};
void CreateHT(vector<double>&weight,vector<HTNode>&ht){
int n=weight.size();
if(n<=1)return;
int m=2*n-1;
ht.resize(m);
priority_queue<HeapNode,vector<HeapNode>,greater<HeapNode>>pq;
for(int i=0;i<n;i++){
    ht[i].weight=weight[i];
    pq.push({weight[i],i});

}
for(int  i=n;i<m;i++){
    HeapNode p1=pq.top();pq.pop();
    HeapNode p2=pq.top();pq.pop();
    ht[i].weight=p1.w+p2.w;
    ht[i].lchild=p1.id;
    ht[i].rchild=p2.id;
    ht[p1.id].parent=i;
    ht[p2.id].parent=i;
    pq.push({ht[i].weight,i});

}

}

long long cal(vector<HTNode>&ht,int n){
    long long sum=0;
    for(int i=0;i<n;i++){
    int curr=i;
    int depth=0;
    while(ht[curr].parent!=-1){
        depth++;
        curr=ht[curr].parent;
    }
    sum+=(long long)ht[i].weight*depth;
    }
    return sum;
}

int main(){
int n;
cin>>n;
vector<double>weight;

for(int i=0;i<n;i++){
double val;
cin>>val;
weight.push_back(val);

}
vector<HTNode>ht;
CreateHT(weight,ht);
cout<<cal(ht,n);
return 0;




}
