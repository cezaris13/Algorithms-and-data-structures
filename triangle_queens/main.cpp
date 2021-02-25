#include <iostream>
#define SIZE 20
using namespace std;
bool checkPosition(int board[SIZE][SIZE],int x,int y,int size){
    int i,j;
    for(i=0;i<size-x;i++){//optimise later
       if(board[x][i]==1){
           return 0;
       }
   }
   for (i = x, j = y; j >= 0 && i < size; i++, j--){
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
void print(int board[SIZE][SIZE],int size){
    for(int i=0;i<size;i++){
        printf("%*s",size-i,"");
        int tempx=i;
        for(int j=0;j<=i;j++){
            printf("%d ",board[tempx][j]);
            tempx--;
        }
        printf("\n");
  }
}
bool cities(int board[SIZE][SIZE],int index,int num_of_cities,int size){
    if(countCities(board)==num_of_cities){
        // print(board);
        return 1;
    }
    for(int i=0;i<size-index;i++){
        if(checkPosition(board,i,index,size)){
            board[i][index]=1;
            if(cities(board,index+1,num_of_cities,size)){
                return 1;
            }
            // cities(board,index+1,num_of_cities);
            board[i][index]=0;
        }
    }
    return 0;
}
int main() {
    int size;
    printf("enter size of triangle:");
    cin>>size;
    // for(size=1;size<=20;size++){
        // printf("%d. triangle\n",size);
        if(size>SIZE){
            printf("this triangle is too large : ( \n");
            return 0;
        }
        int board[SIZE][SIZE]={{0}};
        for(int i=0;i<size;i++){
            for(int j=size-i;j<size;j++){
                board[i][j]=-1;
            }
        }
        int num_of_cities=(2*size+1)/3;//there is proven formula for that
        printf("number of cities: %d\n\n",num_of_cities);
        if(cities(board,0,num_of_cities,size)){
            print(board,size);
        }
        else{
            printf("solution does not exist\n");
        }
    // }
    return 0;
}
