#include <bits/stdc++.h>
using namespace std;

vector<int> AllDivisor(int n){
    vector<int> result;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            result.push_back(i);
            if (i != n/i)
                result.push_back(n/i);
        }
            
    }
    sort(result.begin(),result.end());
    return result;
}

int main(){
    int num;
    cout<<"Enter Num"<<endl;
    cin>>num;
    vector<int> result = AllDivisor(num);
    for(auto i: result)
        cout<<i<<" ";

}