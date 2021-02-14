#include <iostream>
#define SIZE 20
using namespace std;
bool checkPosition(int lenta[SIZE][SIZE],int x,int y){
    int i,j;
    for(i=0;i<SIZE;i++){
       if(lenta[x][i]==1){
           return 0;
       }
   }
   for (i = x, j = y; i >= 0 && j >= 0; i--, j--){
       if (lenta[i][j]){
           return 0;
       }
   }
   for (i = x, j = y; j >= 0 && i < SIZE; i++, j--){
       if (lenta[i][j]){
           return 0;
       }
   }
   return 1;
}
bool queens(int lenta[SIZE][SIZE],int index){
    if(index==SIZE){
        return 1;
    }
    for(int i=0;i<SIZE;i++){
        if(checkPosition(lenta,i,index)){
            lenta[i][index]=1;
            if(queens(lenta,index+1)){
                return 1;
            }
            lenta[i][index]=0;
        }
    }
    return 0;
}

int main() {
    int lenta[SIZE][SIZE]={{0}};
    if(queens(lenta,0)){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                printf("%d",lenta[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("solution does not exist\n");
    }
    return 0;
}
