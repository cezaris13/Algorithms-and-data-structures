#include <bits/stdc++.h>
//https://www.cin.ufpe.br/~pcp/nonattacking_queens.pdf (proof of (2n+1)/3 formula)
#define SIZE 30
using namespace std;
long op_count=0;

// int countCities(int board[SIZE][SIZE]){
//     int count=0;
//     for(int i=0;i<SIZE;i++){
//         for(int j=0;j<SIZE;j++){
//             op_count++;
//             if(board[i][j]==1){
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// bool checkPosition(int board[SIZE][SIZE],int x,int y,int size){
//     int i,j;
//     for(i=0;i<size-x;i++){//optimise later
//        if(board[x][i]==1){
//            op_count++;
//            return 0;
//        }
//    }
//     for (i = x, j = y; j >= 0 && i < size; i++, j--){
//         op_count++;
//        if (board[i][j]==1){
//            return 0;
//        }
//    }
//    return 1;
// }
bool checkPosition(int board[SIZE][SIZE],int x,int y,int size){
    int i,j;
    for (i=x, j=y; j>=0 && i<size; i++, j--){
        op_count++;
        if (board[i][j]==1){
            return 0;
        }
    }
    return 1;
}
void print(int board[SIZE][SIZE],int size){//fancy printing
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
bool cities(int board[SIZE][SIZE],int index,int num_of_cities,int size,bool visited[],int count){
    // if(countCities(board)==num_of_cities){
    if(count==num_of_cities){
        return 1;
    }
    for(int i=0;i<size-index;i++){//go through all elements in
        op_count++;
        if(checkPosition(board,i,index,size)&&!visited[i]){
        // if(checkPosition(board,i,index,size)){
            board[i][index]=1;
            visited[i]=1;
            if(cities(board,index+1,num_of_cities,size,visited,count+1)){//backtracking
                return 1;
            }
            visited[i]=0;
            board[i][index]=0;
        }
    }
    return 0;
}
int main() {
    int size;
    clock_t t;
    printf("enter size of triangle:");
    cin>>size;
    bool visited[size]={0};
    if(size>SIZE){
        printf("this triangle is too large : ( \n");
        return 0;
    }
    int board[SIZE][SIZE]={{0}};
    int num_of_cities=(2*size+1)/3;//there is proven formula for that
    printf("number of cities: %d\n\n",num_of_cities);
    t = clock();
    if(cities(board,0,num_of_cities,size,visited,0)){
        print(board,size);
    }
    else{
        printf("solution does not exist\n");
    }
    t = clock() - t;
    printf("total time: %fsek.\ntotal operations: %ld\n",((double)t)/CLOCKS_PER_SEC,op_count);
    return 0;
}
//optimized:     size-20 : time- 0.92sek op_count=213942791
//not optimized: size-20 : time- 6.57sek op_count=2469571168
