#include <iostream>
#define SIZE 8
using namespace std;
pair<int,int> moves[8]={make_pair(1,2),make_pair(1,-2),make_pair(-1,2),make_pair(-1,-2),make_pair(2,1),make_pair(2,-1),make_pair(-2,1),make_pair(-2,-1)};
void printArray(int lenta[SIZE][SIZE]){
    freopen("rez.txt","aw",stdout);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            printf("%2.1d ",lenta[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
bool solve(int lenta[SIZE][SIZE],int index,int x,int y){
    if(index==SIZE*SIZE){
        return 1;
    }
    printArray(lenta);
    for(int i=0;i<8;i++){
        int newx=x+moves[i].first;
        int newy=y+moves[i].second;
        if(newx>=0 && newx<SIZE && newy>=0 && newy<SIZE && lenta[newx][newy]==0){
            lenta[x][y]=index;
            if(solve(lenta,index+1,newx,newy)){
                return 1;
            }
            lenta[x][y]=0;
        }
    }
    return 0;
}
int main() {
    int lenta[SIZE][SIZE]={{0}};
    if(solve(lenta,1,0,0)){
     printArray(lenta);
    }

    return 0;
}
