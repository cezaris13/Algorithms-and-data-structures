#include <iostream>
#define SIZE 8 // kazkodel su n=8 failina
using namespace std;
int movesx[8] = {2,1,-1,-2,-2,-1,1,2};
int movesy[8] = {1,2,2,1,-1,-2,-2,-1};

void printArray(int board[SIZE][SIZE]){
    // freopen("rez.txt","aw",stdout);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            printf("%2.1d ",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
bool solve(int board[SIZE][SIZE],int index,int x,int y){
    int newx,newy;
    if(index==SIZE*SIZE){
        board[x][y]=SIZE*SIZE;
        return 1;
    }
    for(int i=0;i<8;i++){
        newx=x+movesx[i];
        newy=y+movesy[i];
        if(newx>=0 && newx<SIZE && newy>=0 && newy<SIZE && board[newx][newy]==0){
            board[x][y]=index;
            if(solve(board,index+1,newx,newy)){
                return 1;
            }
            board[x][y]=0;
        }
    }
    return 0;
}
int main() {
    int board[SIZE][SIZE]={{0}};
    if(solve(board,1,0,0)==1){
        printArray(board);
    }
    else{
        printf("solution does not exist");
    }
    return 0;
}
