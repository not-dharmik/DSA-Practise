#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

char exor(char a,char b){
    if(a==b)    
        return '0';
    else
        return '1';
}

void crc(char data[], char key[],char data1[])
{
int datalen = strlen(data);
int keylen = strlen(key);

for(int i=0;i<keylen-1;i++)                //appending n-1 zeroes to data
data[datalen+i]='0';
data[datalen+keylen-1]='\0';

int codelen = datalen+keylen-1;                //lenght of appended data word

char temp[20],rem[20],rem1[20],temp1[20];   // added rem1 and temp1

for(int i=0;i<keylen;i++)
rem[i]=data[i];                    //considering n bits of data for each step of binary division/EXOR 

for(int j=keylen;j<=codelen;j++)
{
    for(int i=0;i<keylen;i++)
    temp[i]=rem[i];                // remainder of previous step is divident of current step

    if(rem[0]=='0')                //if 1's bit of remainder is 0 then shift the rem by 1 bit
    {
        for(int i=0;i<keylen-1;i++)
            rem[i]=temp[i+1];
    }
    else                    //else exor the divident with generator key
    {    
        for(int i=0;i<keylen-1;i++)
            rem[i]=exor(temp[i+1],key[i+1]);
            
    }
    if(j!=codelen)
        rem[keylen-1]=data[j];        //appending next bit of data to remainder obtain by division
    else
        rem[keylen-1]='\0';
}
    
for(int i=0;i<keylen-1;i++)
data[datalen+i]=rem[i];                //replace n-1 zeros with n-1 bit CRC
data[codelen]='\0';
cout<<rem;
//<<"\nDataword="<<data;
// adding new program from here 
for(int i=0;i<keylen;i++)
rem1[i]=data1[i];                    //considering n bits of data for each step of binary division/EXOR 
//cout<<"performing operation on  = "<< data1;
for(int j=keylen;j<=codelen;j++)
{
    for(int i=0;i<keylen;i++)
    temp1[i]=rem1[i];                // remainder of previous step is divident of current step

    if(rem1[0]=='0')                //if 1's bit of remainder is 0 then shift the rem by 1 bit
    {
        for(int i=0;i<keylen-1;i++)
            rem1[i]=temp1[i+1];
    }
    else                    //else exor the divident with generator key
    {    
        for(int i=0;i<keylen-1;i++)
            rem1[i]=exor(temp1[i+1],key[i+1]);
            
    }
    if(j!=codelen)
        rem1[keylen-1]=data1[j];        //appending next bit of data to remainder obtain by division
    else
        rem1[keylen-1]='\0';
}
//cout<<"\nrem1= "<<rem1;
if (rem1[0]=='0' && rem1[1]=='0' && rem1[2]=='0')
    cout<<"\n0";
else
    cout<<"\n1";    
//clasong new program from here
}

int main()
{
char key[20],data[20],data1[20];
int datalen , keylen;
cout<<"Enter the data length:";
cin>>datalen;
cout<<"Enter the data:";
cin>>data;
cout<<"Enter the key length";
cin>>keylen;
cout<<"Enter the key:";
cin>>key;
cout<<"Enter the data1:";
cin>>data1;
if(datalen>=0 && keylen>=0){
    crc(data,key,data1);                        // generate crc
}
return 0;
}