#include <bits/stdc++.h>
using namespace std;

int AND(char a, char b){
    if (a==b && a==1)
        return 1;
    else
        return 0;
}

int XOR(char a, char b){
    if (a==b)
        return 0;
    else
        return 1;
}

string complement(string data){
	for (int i = 0; i < data.length(); i++) {
		if (data[i] == '0')
			data[i] = '1';
		else
			data[i] = '0';
	}

	return data;
}

// string binarySum(string a, string b,int n){
//     string add = "";
//     string final="";
// 	int sum = 0, carry = 0;
//     for(int i=(n-1);i>=0;i--){
//         sum += (b[i] - '0') + (a[i] - '0');
// 		carry = sum / 2;
//         if (sum == 0) {
// 				add = '0' + add;
// 				sum = carry;
// 		}
// 		else if (sum == 1) {
// 				add = '1' + add;
// 				sum = carry;
// 		}
// 		else if (sum == 2) {
// 				add = '0' + add;
// 				sum = carry;
// 		}
// 		else {
// 				add = '1' + add;
// 				sum = carry;
// 		}
//         if (carry == 1) {
//             for (int l = add.length() - 1; l >= 0;l--){
// 		    	if (carry == 0) 
// 		    		final = add[l] + final;
		    	
// 		    	else if (((add[l] - '0') + carry) % 2 == 0){
// 		    		final = "0" + final;
// 		    		carry = 1;
// 		    	}
// 		    	else {
// 		    		final = "1" + final;
// 		    		carry = 0;
// 		    	}
// 		    }
//             a = final;
//         }
//         else    
//             a=add;   
//     }
//     return a;
// }

string checkSum( string st, int bit){
    int num = st.length();
    string ans = "";
    string result = "";
    if (num % bit != 0) {
        int extra = bit - (num % bit);
        for (int i = 0; i < extra; i++) {
            st = '0' + st;
        } 
    }
    for(int i=0;i<bit;i++)
        result += st[i];

    for(int i=bit;i<num;i+=bit){

        string next=""; //stores binary of next block

        for(int j=i; j<(i+bit);j++)
            next += st[j];

        //ans += binarySum(result,next,bit); 
        string add = "";
        string final="";
    	int sum = 0, carry = 0;
        for(int k=(bit-1);k>=0;k--){
            sum += (next[k] - '0') + (result[k] - '0');
    		carry = sum / 2;
            if (sum == 0) {
    				add = '0' + add;
    				sum = carry;
    		}
    		else if (sum == 1) {
    				add = '1' + add;
    				sum = carry;
    		}
    		else if (sum == 2) {
    				add = '0' + add;
    				sum = carry;
    		}
    		else {
    				add = '1' + add;
    				sum = carry;
    		}
            if (carry == 1) {
                for (int l = add.length() - 1; l >= 0;l--){
    		    	if (carry == 0) 
    		    		final = add[l] + final;
    
    		    	else if (((add[l] - '0') + carry) % 2 == 0){
    		    		final = "0" + final;
    		    		carry = 1;
    		    	}
    		    	else {
    		    		final = "1" + final;
    		    		carry = 0;
    		    	}
    		    }
                result = final;
            }
            else    
                result=add;   
        }
    }
    return complement(result); 
    
}

int main(){
    string sent,recieve;
    int n;          //no. of blk
    cin>>sent>>n>>recieve; 
    int k = (sent.length())/n;  // no. (bits) in each block

    cout<<checkSum(sent,k)<<endl; 

    string receiveChecksum = checkSum(recieve + sent, k);

	// If receivers checksum value is 0
	if (count(receiveChecksum.begin(), receiveChecksum.end(), '0') == k){
		cout<<"0";
	}
	else {
		cout<<"1";
	}


    return 0;
}