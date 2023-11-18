#include <bits/stdc++.h>
using namespace std;
int main(){
    int frame,window;
    cin>>frame>>window;
    srand(time(NULL));
    int pos=0, itr=0;
    while( pos<=frame-window){
        for(int i=0;i<window;i++){
            cout<<"sent Frame "<<i+1<<endl;
            pos++;
        }
    }

    return 0;
}