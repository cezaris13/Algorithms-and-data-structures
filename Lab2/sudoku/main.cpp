#include <iostream>
#define SIZE 9
using namespace std;
void print(int sudoku[][SIZE]){
    char line[]="----------------------";
    for(int i=0;i<SIZE;i++){
        if(i%3==0&&i>0){
            printf("%s\n",line);
        }
        for(int j=0;j<SIZE;j++){
            if(j%3==0&&j>0){
                printf(" %c",'|');
            }
            printf("%2.1d",sudoku[i][j]);
        }
        printf("\n");
    }
}
bool find_unassigned(int sudoku[][SIZE],int &x,int &y){
    for(x=0;x<SIZE;x++){
        for(y=0;y<SIZE;y++){
            if(sudoku[x][y]==0){
                return 1;
            }
        }
    }
    return 0;
}
bool check_sudoku(int sudoku[][SIZE],int x, int y,int val){
    for(int i=0;i<SIZE;i++){
        if(val==sudoku[x][i]){
            return 0;
        }
    }
    for(int i=0;i<SIZE;i++){
        if(val==sudoku[i][y]){
            return 0;
        }
    }
    int minx=x-x%3;
    int miny=y-y%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(sudoku[minx+i][miny+j]==val){
                return 0;
            }
        }
    }
    return 1;
}
bool solve(int sudoku[][SIZE]){
    int x,y;
    if(!(find_unassigned(sudoku,x,y))){
        return 1;
    }
    for(int i=1;i<=SIZE;i++){
        if(check_sudoku(sudoku,x,y,i)){
            sudoku[x][y]=i;
            if(solve(sudoku)){
                return 1;
            }
            sudoku[x][y]=0;
        }
    }
    return 0;
}
int main() {
    int sudoku[SIZE][SIZE]={ { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    freopen("duota.txt","r",stdin);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            cin>>sudoku[i][j];
        }
    }

    if(solve(sudoku)){
        print(sudoku);
    }
    else{
        printf("no solution exists");
    }
    return 0;
}
