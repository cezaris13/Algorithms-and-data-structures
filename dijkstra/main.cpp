#include <bits/stdc++.h>
#define infinity 100000
using namespace std;
void dijkstra(int size,int **graph,int start, int finish){
    priority_queue<pair<int,int> > pQueue;
    bool visited[size];
    int distances[size];
    for(int i=0;i<size;i++){
        distances[i]=infinity;
        visited[i]=0;
    }
    distances[start]=0;
    pQueue.push(make_pair(0,start));
    while(!pQueue.empty()){
        int curr=pQueue.top().second;
        pQueue.pop();
        if(!visited[curr]){
            visited[curr]=1;
            for(int i=0;i<size;i++){
                if(graph[curr][i]!=0){
                    if(distances[curr]+graph[curr][i]<distances[i]){
                        distances[i]=distances[curr]+graph[curr][i];
                        pQueue.push(make_pair(-distances[i], i));
                    }
                }
            }
        }
    }
    printf("distance from %d to %d is: %d\n",start,finish,distances[finish]);
}
void dfs(int size,int **graph,int pos, bool visited[]){
    visited[pos]=1;
    for(int i=0;i<size;i++){
        if(graph[pos][i]!=0 && visited[i]==0){
            dfs(size,graph,i,visited);
        }
    }
}
bool checkIfReachable(int size,int **graph,int start,int finish){
    bool visited[size];
    for(int i=0;i<size;i++){
        visited[i]=0;
    }
    dfs(size,graph,start,visited);
    if(visited[finish]){
        return 1;
    }
    else{
        return 0;
    }
}

int main(int argc, char *argv[]) {
    ifstream fd("data.txt");
    int size;
    fd>>size;
    int **graph=(int**)malloc(size*sizeof(int*));
    for(int i=0;i<size;i++){
        graph[i]=(int*)malloc(size*sizeof(int));
        for(int j=0;j<size;j++){
            fd>>graph[i][j];
        }
    }
    fd.close();
    int start,finish;
    char print;
    printf("print graph? y/n\n");
    scanf("%c",&print);
    if(print=='y'){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                printf("%2.1d ",graph[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("enter cities\n");
    cin>>start>>finish;
    if(start>=size||finish>=size||start<0||finish<0){
        printf("invalid city number\n");
        return 0;
    }
    if(checkIfReachable(size,graph,start,finish)){
        dijkstra(size,graph,start,finish);
    }
    else{
        printf("there is no route between %d and %d",start,finish);
    }
    for(int i=0;i<size;i++){
        free(graph[i]);
    }
    free(graph);
    return 0;
}
