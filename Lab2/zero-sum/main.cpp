#include <bits/stdc++.h>

using namespace std;
bool solve(int arr[],int size){
    unordered_set<int> sums;
    int temp_sum=0;
    for(int i=0;i<size;i++){
        temp_sum+=arr[i];
        if(sums.find(temp_sum)!=sums.end()||temp_sum==0){
            //to print numbers which sum up to 0
            // int needed_sum=temp_sum;
            // for(int j=i;j>=0;j--){
            //     printf("%d ",arr[j]);
            //     temp_sum-=arr[j];
            //     if(needed_sum==temp_sum){
            //         break;
            //     }
            // }
            return 1;
        }
        sums.insert(temp_sum);
    }
    return 0;
}
int main() {
    int arr[]={-8,-2,1,2,7,10,15,23};
    int size=sizeof(arr)/sizeof(arr[0]);
    if(solve(arr,size)){
        printf("solution exists");

    }
    else{
        printf("no solution");
    }
    return 0;
}
