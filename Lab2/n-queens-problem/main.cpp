#include <iostream>
#define SIZE 21
using namespace std;
bool checkPosition(int board[SIZE][SIZE],int x,int y){
    int i,j;
    for(i=0;i<SIZE;i++){
       if(board[x][i]==1){
           return 0;
       }
   }
   for (i = x, j = y; i >= 0 && j >= 0; i--, j--){
       if (board[i][j]){
           return 0;
       }
   }
   for (i = x, j = y; j >= 0 && i < SIZE; i++, j--){
       if (board[i][j]){
           return 0;
       }
   }
   return 1;
}
bool queens(int board[SIZE][SIZE],int index){
    if(index==SIZE){
        return 1;
    }
    for(int i=0;i<SIZE;i++){
        if(checkPosition(board,i,index)){
            board[i][index]=1;
            if(queens(board,index+1)){
                return 1;
            }
            board[i][index]=0;
        }
    }
    return 0;
}

int main() {
    int board[SIZE][SIZE]={{0}};
    if(queens(board,0)){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                printf("%d",board[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("solution does not exist\n");
    }
    return 0;
}
