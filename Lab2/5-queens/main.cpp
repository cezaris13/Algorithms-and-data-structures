#include <bits/stdc++.h>
#define SIZE 8
using namespace std;
bool checkUnused(int board[SIZE][SIZE]){
    bool vis[SIZE][SIZE]={{0}};
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(board[i][j]==1){
                for(int k=0;k<SIZE;k++){
                    vis[k][j]=1;
                    vis[i][k]=1;
                }
                int tempx=i,tempy=j;
                while(tempx<SIZE && tempy>=0){
                    vis[tempx][tempy]=1;
                    tempy--;
                    tempx++;
                }
                tempx=i;
                tempy=j;
                while(tempx<SIZE && tempy<SIZE){
                    vis[tempx][tempy]=1;
                    tempy++;
                    tempx++;
                }
                tempx=i;
                tempy=j;
                while(tempx>=0 && tempy>=0){
                    vis[tempx][tempy]=1;
                    tempy--;
                    tempx--;
                }
                tempx=i;
                tempy=j;
                while(tempx>=0 && tempy<SIZE){
                    vis[tempx][tempy]=1;
                    tempy++;
                    tempx--;
                }
            }
        }
    }
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(!vis[i][j]){
                return 0;
            }
        }
    }
    return 1;
}
int countQueens(int board[SIZE][SIZE]){
    int count=0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(board[i][j]==1){
                count++;
            }
        }
    }
    return count;
}
bool solve(int board[SIZE][SIZE],vector<pair<int,pair<int,int> > > probs,int index){
    if(countQueens(board)==5){
        if(checkUnused(board)){
            // for(int i=0;i<SIZE;i++){
            //     for(int j=0;j<SIZE;j++){
            //         printf("%2.1d",board[i][j]);
            //     }
            //     printf("\n");
            // }
            // printf("\n");
            return 1;
        }
        else{
            return 0;
        }
    }
    for(int i=index;i<SIZE*SIZE;i++){
       if(board[probs[i].second.first][probs[i].second.second]!=1){
           board[probs[i].second.first][probs[i].second.second]=1;
           if(solve(board,probs,i+1)){
               return 1;
           };
           // solve(board,probs,i+1);
           board[probs[i].second.first][probs[i].second.second]=0;
       }
    }
    return 0;
}
int Calc(int x,int y){
    int calc=15;
    int tempx=x,tempy=y;
    while(tempx<SIZE && tempy>=0){
        calc++;
        tempy--;
        tempx++;
    }
    tempx=x;
    tempy=y;
    while(tempx<SIZE && tempy<SIZE){
        calc++;
        tempy++;
        tempx++;
    }
    tempx=x;
    tempy=y;
    while(tempx>=0 && tempy>=0){
        calc++;
        tempy--;
        tempx--;
    }
    tempx=x;
    tempy=y;
    while(tempx>=0 && tempy<SIZE){
        calc++;
        tempy++;
        tempx--;
    }
    calc-=4;
    return calc;
}
int main() {
    // freopen("rez.txt","w",stdout);
    int board[SIZE][SIZE]={{0}};
    vector<pair<int,pair<int,int> > > probs;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            probs.push_back(make_pair(Calc(i,j),make_pair(i,j)));
        }
    }
    sort(probs.rbegin(),probs.rend());
    if(solve(board,probs,0)){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                printf("%2.1d",board[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
} 
