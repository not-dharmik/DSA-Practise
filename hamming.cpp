#include<iostream>
#include<math.h>
using namespace std;
char binary(int a,int b)
{
    int bin[4];
    int i;
    for(i=3;i>=0;i--){
        bin[i]=a%2;
        a=a/2;
    }
    
    if(bin[4-b]==1)
        return '1';
    else
        return '0';
}
int main()
{
    int m,r;
    string data;
    cin>>m>>data;
    if(m>1 && m<15){
        for(int i=1;i<=m;i++){
            if((pow(2,i))>=(m+i+1)){
                r=i;
                break;
            }
        }
        cout<<r<<endl;
        int range=m+r+1;
        char data_send[range],p;
        int t=r-1,k=0;
        for(int i=range-1;i>=1;i--){
            if(i!=pow(2,t))
                data_send[i]=data[k++];
            else
            {
                data_send[i]='%';
                t--;
            }
        }
        int c;
        for(int i=0;i<r;i++){
            t=pow(2,i);
            c=0;
            for(int j=1;j<(m+r+1);j++){
                p=binary(j,i+1);
                if(p=='1' && data_send[j]=='1')
                    c++;
            }
            if(c%2!=0)
                data_send[t]='1';
            else
                data_send[t]='0';
        }
        for(int i=0;i<r;i++){
            t=pow(2,i);
            cout<<data_send[t]<<endl;
        }
        for(int i=m+r;i>=1;i--)
            cout<<data_send[i];
    }
}