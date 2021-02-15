#include <iostream>
#define SIZE 8 // kazkodel su n=8 failina
using namespace std;
int movesx[8] = {2,1,-1,-2,-2,-1,1,2};
int movesy[8] = {1,2,2,1,-1,-2,-2,-1};

void printArray(int lenta[SIZE][SIZE]){
    // freopen("rez.txt","aw",stdout);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            printf("%2.1d ",lenta[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
bool solve(int lenta[SIZE][SIZE],int index,int x,int y){
    int newx,newy;
    if(index==SIZE*SIZE){
        lenta[x][y]=SIZE*SIZE;
        return 1;
    }
    for(int i=0;i<8;i++){
        newx=x+movesx[i];
        newy=y+movesy[i];
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
    if(solve(lenta,1,0,0)==1){
        printArray(lenta);
    }
    else{
        printf("solution does not exist");
    }
    return 0;
}
