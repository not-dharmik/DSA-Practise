#include<bits/stdc++.h>
using namespace std;

string rem(string data, string div){
    string rem="",quo="";
    int x = data.length();
    int y = div.length();
	if (x % y != 0) {
		int extra = y - (x % y);
		for (int i = 0; i < extra; i++) {
			data += '0';
		}
        cout<<extra;
	}
    
}

int main()
{
	string data,div,key;
    string crc;
	int x,y;
    cin>>x>>data>>y>>div>>key;
	
	crc = rem(data, div);
	
	return 0;
}

// This code is contributed by MuskanKalra1
