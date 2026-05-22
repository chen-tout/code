#include<iostream>
using namespace std;
struct adjNode{
    int adjvex;
    adjNode*nextarc;
};
struct HNode{
    adjNode*firstarc;
};
 int a[1005][1005]={0};
  HNode adjlist[1005];
  int visited[1005]={0};

  void dfs(int v){
    cout<<v<<" ";
    visited[v]=1;
    adjNode*p=adjlist[v].firstarc;
    while(p){
        if(visited[p->adjvex]==0){
            dfs(p->adjvex);
        }
        p=p->nextarc;
        }
    }
  



int main(){
    int n,m;
    cin>>n>>m;
   
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        a[u][v]=a[v][u]=1;
    }
   
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
    int s;
    cin>>s;
    dfs(s);
    return 0;

}