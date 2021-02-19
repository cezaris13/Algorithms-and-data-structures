#include <iostream>
#define SIZE 20
using namespace std;
bool checkPosition(int board[SIZE][SIZE],int x,int y){
    int i,j;
    for(i=0;i<SIZE-x;i++){//optimise later
       if(board[x][i]==1){
           return 0;
       }
   }
   for (i = x, j = y; j >= 0 && i < SIZE; i++, j--){
       if (board[i][j]==1){
           return 0;
       }
   }
   return 1;
}
int countCities(int board[SIZE][SIZE]){
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
void print(int board[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        printf("%*s",SIZE-i,"");
        int tempx=i;
        for(int j=0;j<=i;j++){
            printf("%d ",board[tempx][j]);
            tempx--;
        }
        printf("\n");
  }
}
bool cities(int board[SIZE][SIZE],int index,int num_of_cities){
    if(countCities(board)==num_of_cities){
        // print(board);
        return 1;
    }
    for(int i=0;i<SIZE-index;i++){
        if(checkPosition(board,i,index)){
            board[i][index]=1;
            if(cities(board,index+1,num_of_cities)){
                return 1;
            }
            // cities(board,index+1,num_of_cities);
            board[i][index]=0;
        }
    }
    return 0;
}
int main() {
    int board[SIZE][SIZE]={{0}};
    for(int i=0;i<SIZE;i++){
        for(int j=SIZE-i;j<SIZE;j++){
            board[i][j]=-1;
        }
    }
    int num_of_cities=(2*SIZE+1)/3;
    printf("number of cities: %d\n",num_of_cities);
    if(cities(board,0,num_of_cities)){
        print(board);
    }
    else{
        printf("solution does not exist\n");
    }
    return 0;
}
