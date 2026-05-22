#include<iostream>
#include<string>
using namespace std;

const int MAXV=100;
const int INF=0x3f3f3f3f;
class MatGraph{
    public:
    int edge[MAXV][MAXV];
    int n,e;
    string vexs[MAXV];
    void CreateGraph(int a[][MAXV],int n,int e){
        this->n=n;
        this->e=e;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                edge[i][j]=a[i][j];
            }
        }
    }
    void DispMatGraph(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(edge[i][j]=INF){
                    printf("%4s","inf");
                }
                else{
                    printf("%4d",edge[i][j]);
                }
            }
            printf("\n");
        }
    }
};

struct ArcNode{
    int adjvex;
    int weight;
    ArcNode* nextarc;
};
struct HNode{
    string info;
    ArcNode*firstarc;
};
class adjGraph{
    public:
    HNode adjlist[MAXV];
    int n,e;
    adjGraph(){
        for(int i=0;i<n;i++){
            adjlist[i].firstarc=NULL;


        }
    }
    ~adjGraph(){}
    void CreateGraph(int a[][MAXV],int n,int e){
        this->n=n;this->e=e;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(a[i][j]!=INF&&a[i][j]!=0){
                    ArcNode*p=new ArcNode;
                    p->adjvex=j;
                    p->weight=a[i][j];
                    p->nextarc=adjlist[i].firstarc;
                    adjlist[i].firstarc=p;
                    
            }
        }
    }
}
};

