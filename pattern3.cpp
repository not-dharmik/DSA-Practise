#include <iostream>
using namespace std;
int main(){

    int row,col;
    row=5;

    for(int i=1;i<=row;i++){
        for(int j=1;j<=(row-i+1);j++){
            cout<<"*";
        }cout<<"\n";
    }
    return 0;
}