#include <bits/stdc++.h>
#define SIZE 10
using namespace std;
int finalLenta[SIZE][SIZE]={{0}};
bool found=0;
bool checkPosition(int lenta[][SIZE],int x,int y){
   for(int i=0;i<SIZE;i++){
       if(lenta[i][y]==1||lenta[x][i]==1){
           return 0;
       }
   }
   int xx=x,n=0;
   while(xx!=SIZE){
       if(lenta[xx][y+n]==1||lenta[xx][y-n]==1){
           return 0;
       }
       n++;
       xx++;
   }
   xx=x;
   n=0;
   while(xx!=-1){
      if(lenta[xx][y+n]==1||lenta[xx][y-n]==1){
         return 0;
      }
      n++;
      xx--;
   }
   return 1;
}
void queens(int lenta[][SIZE],int index){

    if(index==SIZE){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                finalLenta[i][j]=lenta[i][j];
            }
        }
        found=1;
        return;
    }
    if(!found){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                if(checkPosition(lenta,i,j)){
                    lenta[i][j]=1;
                    queens(lenta,index+1);
                    lenta[i][j]=0;
                }
            }
        }
    }

}

int main(int argc, char *argv[]) {
    int n;
    n=SIZE;
    int lenta[SIZE][SIZE]={{0}};
    queens(lenta,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<finalLenta[i][j];
        }
        cout<<endl;
    }
    return 0;
}
