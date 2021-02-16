#include <bits/stdc++.h>
#define SIZE 8
using namespace std;
int movesx[8] = {2,1,-1,-2,-2,-1,1,2};
int movesy[8] = {1,2,2,1,-1,-2,-2,-1};
bool checkUnused(int lenta[SIZE][SIZE]){
    bool vis[SIZE][SIZE]={{0}};
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(lenta[i][j]==1){
                vis[i][j]=1;
                for(int k=0;k<8;k++){
                    int newx=i+movesx[k];
                    int newy=j+movesy[k];
                    if(newx>=0 && newx<SIZE && newy>=0 && newy<SIZE){
                        vis[newx][newy]=1;
                    }
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
int countKnights(int lenta[SIZE][SIZE]){
    int count=0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(lenta[i][j]==1){
                count++;
            }
        }
    }
    return count;
}
bool solve(int lenta[SIZE][SIZE],vector<pair<int,pair<int,int> > > probs,int index){
    if(countKnights(lenta)==12){
  for(int i=0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    printf("%2.1d",lenta[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        if(checkUnused(lenta)){
            // for(int i=0;i<SIZE;i++){
            //     for(int j=0;j<SIZE;j++){
            //         printf("%2.1d",lenta[i][j]);
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
       if(lenta[probs[i].second.first][probs[i].second.second]!=1){
           lenta[probs[i].second.first][probs[i].second.second]=1;
           if(solve(lenta,probs,i+1)){
               return 1;
           };
           // solve(lenta,probs,i+1);
           lenta[probs[i].second.first][probs[i].second.second]=0;
       }
    }
    return 0;
}
int Calc(int x,int y){
     int calc=0;
     for(int i=0;i<8;i++){
         int newx=x+movesx[i];
         int newy=y+movesy[i];
         if(newx>=0 && newx<SIZE && newy>=0 && newy<SIZE){
             calc++;
         }
     }
    return calc;
}
int main() {
    // freopen("rez.txt","w",stdout);
    int index=0;
    int lenta[SIZE][SIZE]={{0}};
    vector<pair<int,pair<int,int> > > probs;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            // printf("%2.1d",Calc(i,j));
            probs.push_back(make_pair(Calc(i,j),make_pair(i,j)));
        }
        // printf("\n");
    }
    sort(probs.rbegin(),probs.rend());
    // for(int i=0;i<probs.size();i++){
    //     printf("%2.1d. %d (%d %d)\n",i+1,probs[i].first,probs[i].second.first,probs[i].second.second);
    // }
    if(solve(lenta,probs,0)){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                printf("%2.1d",lenta[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
