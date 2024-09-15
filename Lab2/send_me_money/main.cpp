#include <bits/stdc++.h>

using namespace std;
bool solve(vector<int> &total_ans,bool taken[10]){
    if(total_ans.size()==8){
        if(1000*total_ans[0]+100*total_ans[1]+10*total_ans[2]+total_ans[3]+1000*total_ans[4]+100*total_ans[5]+10*total_ans[6]+total_ans[1]==10000*total_ans[4]+1000*total_ans[5]+100*total_ans[2]+10*total_ans[1]+total_ans[7]){
            if(total_ans[4]!=0){
                return 1;
            }
        }
        return 0;
    }
    for(int i=0;i<10;i++){
        if(!taken[i]){
            total_ans.push_back(i);
            taken[i]=1;
            if(solve(total_ans,taken)){
                return 1;
            }
            total_ans.pop_back();
            taken[i]=0;
        }
    }
    return 0;
}
int main() {
    vector<int>total_ans;
    bool visited[10]={0};
    if(solve(total_ans,visited)){
        printf(" %d%d%d%d\n %d%d%d%d\n%d%d%d%d%d",total_ans[0],total_ans[1],total_ans[2],total_ans[3],total_ans[4],total_ans[5],total_ans[6],total_ans[1],total_ans[4],total_ans[5],total_ans[2],total_ans[1],total_ans[7]);
    }
    return 0;
}
