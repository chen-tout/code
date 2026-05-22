#include<iostream>
using namespace std;
struct adjNode{
    int adjvex;
    adjNode*nextarc;

};
struct Hnode{
    adjNode*firstarc;
};
int main(){
    int n,m;
    cin>>n>>m;
    int a[105][105]={0};
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        a[u][v]=a[v][u]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    Hnode adjlist[105];
    for(int i=0;i<=n;i++){
        adjlist[i].firstarc=NULL;
    }
    for(int i=1;i<=n;i++){
        for(int j=n;j>=1;j--){
            if(a[i][j]==1){
                adjNode*p=new adjNode;
                p->adjvex=j;
                p->nextarc=adjlist[i].firstarc;
                adjlist[i].firstarc=p;

            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<i<<":";
        adjNode*p=adjlist[i].firstarc;
        while(p){
            cout<<" "<<p->adjvex;
            p=p->nextarc;
        }
        cout<<endl;
    }
    return 0;
}
