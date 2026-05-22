#include<iostream>
#include<queue>
using namespace std;
const int MAXV=1005;
struct adjNode{
    int adjvex;
    adjNode*nextarc;

};
struct HNode{
    adjNode*firstarc;
};
HNode adjlist[MAXV];
int visited[MAXV]={0};
int a[MAXV][MAXV]={0};
void bfs(int s){
    queue<int>q;
    cout<<s<<" ";
    visited[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        adjNode*p=adjlist[u].firstarc;
        while(p){
            int v=p->adjvex;
            if(visited[v]==0){
                cout<<v<<" ";
                visited[v]=1;
                q.push(v);

            }
            p=p->nextarc;
        }
    }
    
}

int main(){
   int n,m;
    
    if (!(cin >> n >> m)) return 0;
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
    bfs(s);
    return 0;

}
