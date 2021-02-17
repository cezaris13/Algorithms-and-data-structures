#include <iostream>

using namespace std;

int main() {
    for(int s=0;s<=9;s++){
        for(int e=0;e<=9;e++){
            for(int n=0;n<=9;n++){
                for(int d=0;d<=9;d++){
                    for(int m=1;m<=9;m++){
                        for(int o=0;o<=9;o++){
                            for(int r=0;r<=9;r++){
                                for(int y=0;y<=9;y++){
                                    if(1000*s+100*e+10*n+d+1000*m+100*o+10*r+e==10000*m+1000*o+100*n+10*e+y){
                                        int arr[8]={s,e,n,d,m,o,r,y};
                                        bool tru=1;
                                        for(int i=0;i<7;i++){
                                            for(int j=i+1;j<8;j++){
                                                if(arr[i]==arr[j]){
                                                    tru=0;
                                                    j=8;
                                                    i=7;
                                                }
                                            }
                                        }
                                        if(tru){
                                            cout<<s<<e<<n<<d<<endl<<m<<o<<r<<e<<endl<<m<<o<<n<<e<<y<<endl<<endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
