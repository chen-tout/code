#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include <algorithm>

using namespace std;
#include<queue>

struct HTNode{
    double weight;
    int parent,lchild,rchild;

    HTNode(double w=0){
        weight=w;
        parent=-1;
        lchild=-1;
        rchild=-1;
    }
};

struct HeapNode{
    double w;
    int id;
    
    bool operator>(const HeapNode&s)const{
        return w>s.w;
    }
};

void createHT(vector<double>&weight,vector<HTNode>&ht){
    int n=weight.size();
    if(n<=1){return;}
    int m=2*n-1;
    ht.resize(m);
    priority_queue<HeapNode,vector<HeapNode>,greater<HeapNode>>pq;
    for(int i=0;i<n;i++){
        ht[i].weight=weight[i];
        pq.push({weight[i],i});
    }
    for(int i=n;i<m;i++){
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

void CreateHCode(vector<HTNode>&ht,int n){
    for(int i=0;i<n;i++){
        string code="";
        int curr=i;
        int f=ht[i].parent;
        while(f!=-1){
            if(ht[f].lchild==curr){code+='0';}
            if(ht[f].rchild==curr){code+='1';}
            curr=f;
            f=ht[curr].parent;
        }
        reverse(code.begin(),code.end());
        cout << "Weight " << ht[i].weight << " Code: " << code << endl;

    }
}


int main() {
    // 使用你手绘图中的数据：2, 4, 5, 8
    vector<double> weights = {2, 4, 5, 8};
    vector<HTNode> ht;

    createHT(weights, ht);
    CreateHCode(ht, weights.size());
    // 使用英文表头，避免控制台乱码
    cout << "HT Table:" << endl;
    cout << "Index\tWeight\tParent\tLChild\tRChild" << endl;
    cout << "--------------------------------------------" << endl;
    
    for (int i = 0; i < ht.size(); i++) {
        cout << i << "\t" 
             << ht[i].weight << "\t" 
             << ht[i].parent << "\t" 
             << ht[i].lchild << "\t" 
             << ht[i].rchild << endl;
    }

    return 0;
}
                                                                                                                                      
                                                   