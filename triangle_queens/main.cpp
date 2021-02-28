#include <bits/stdc++.h>
//https://www.cin.ufpe.br/~pcp/nonattacking_queens.pdf (proof of (2n+1)/3 formula)
#define SIZE 21
using namespace std;
bool checkPosition(int board[SIZE][SIZE],int x,int y,int size){
    int i,j;
    for (i = x, j = y; j >= 0 && i < size; i++, j--){
        if (board[i][j]==1){
            return 0;
        }
    }
    return 1;
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
bool cities(int board[SIZE][SIZE],int index,int num_of_cities,int size,bool vis[],int count){
    if(count==num_of_cities){
        return 1;
    }
    for(int i=0;i<size-index;i++){
        if(checkPosition(board,i,index,size)&&!vis[i]){
            board[i][index]=1;
            vis[i]=1;
            if(cities(board,index+1,num_of_cities,size,vis,count+1)){
                return 1;
            }
            vis[i]=0;
            board[i][index]=0;
        }
    }
    return 0;
}
int main() {
    int size;
    printf("enter size of triangle:");
    cin>>size;
    bool vis[size]={0};
    if(size>SIZE){
        printf("this triangle is too large : ( \n");
        return 0;
    }
    int board[SIZE][SIZE]={{0}};
    int num_of_cities=(2*size+1)/3;//there is proven formula for that
    printf("number of cities: %d\n\n",num_of_cities);
    if(cities(board,0,num_of_cities,size,vis,0)){
        print(board,size);
    }
    else{
        printf("solution does not exist\n");
    }
    return 0;
}
