#include <iostream>
using namespace std;
int main(){

    int n;
    n=5;

    for(int i=1;i<=n;i++){
        for (int j=0;j<=n;j++){
            if(j<n+1-i)
                cout<<" ";
            else
                cout<<"*";

        }cout<<endl;
    }
    
    return 0;
}