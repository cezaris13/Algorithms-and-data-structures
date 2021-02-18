#include <iostream>
#define SIZE 20
using namespace std;
bool checkPosition(int lenta[SIZE][SIZE],int x,int y){
    int i,j;
    for(i=0;i<SIZE;i++){
       if(lenta[i][y]==1){
           return 0;
       }
   }
for(i=0;i<SIZE;i++){
       if(lenta[x][i]==1){
           return 0;
       }
   }
   for (i = x, j = y; j >= 0 && i < SIZE; i++, j--){
       if (lenta[i][j]==1){
           return 0;
       }
   }
   return 1;
}
int countQueens(int lenta[SIZE][SIZE]){
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
bool queens(int lenta[SIZE][SIZE],int index,int num_of_queens){
    if(countQueens(lenta)==num_of_queens){
   // for(int i=0;i<SIZE;i++){
   //          for(int j=0;j<SIZE;j++){
   //              printf("%2.1d",lenta[i][j]);
   //          }
   //          printf("\n");
   // }
// printf("\n");
   return 1;
    }
    for(int i=0;i<SIZE-index;i++){
        if(checkPosition(lenta,i,index)){
            lenta[i][index]=1;
            if(queens(lenta,index+1,num_of_queens)){
                return 1;
            }
            // queens(lenta,index+1,num_of_queens);
            lenta[i][index]=0;
        }
    }
    return 0;
}

int main() {
    int lenta[SIZE][SIZE]={{0}};
    for(int i=0;i<SIZE;i++){
        for(int j=SIZE-i;j<SIZE;j++){
            lenta[i][j]=-1;
        }
    }
    int num_of_queens=(2*SIZE+1)/3;
    printf("num of queens: %d\n",num_of_queens);
    if(queens(lenta,0,num_of_queens)){
        for(int i=0;i<SIZE;i++){
            printf("%*s",SIZE-i,"");
            int tempx=i;
            for(int j=0;j<=i;j++){
                printf("%d ",lenta[tempx][j]);
                tempx--;
            }
            printf("\n");

        }
    }
    else{
        printf("solution does not exist\n");
    }
    return 0;
}
