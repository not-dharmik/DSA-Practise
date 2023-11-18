#include <bits/stdc++.h>
using namespace std;

string BinSum(string next,string result,int bit){
    string add = "", final = "";
	int sum = 0, carry = 0;
	for (int i = bit - 1; i >= 0; i--) {
		sum += (next[i] - '0') + (result[i] - '0');
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
	}

	if (carry == 1) {
		for (int l = add.length() - 1; l >= 0;l--){
			if (carry == 0) {
				final = add[l] + final;
			}
			else if (((add[l] - '0') + carry) % 2
					== 0) {
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
		result = add;
	
    return result;
}

string complement(string str){
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0')
			str[i] = '1';
		else
			str[i] = '0';
	}

	return str;
}

string checkSum(string str, int bit){
	int n = str.length();
	if (n % bit != 0) {
		int extra = bit - (n % bit);
		for (int i = 0; i < extra; i++) {
			str = '0' + str;
		}
	}

	string result = "";

	for (int i = 0; i < bit; i++)
		result += str[i];
	

	for (int i = bit; i < n; i += bit) {

		string next = "";

		for (int j = i; j < (i + bit); j++) {
			next += str[j];
		}
        result = BinSum(next,result,bit);
	}
	return complement(result);
}

int main()
{
	string sent,recieve;
    int n;                              //no. of blk
    cin>>sent>>n>>recieve; 
    int k = (sent.length())/n;          // no. (bits) in each block

    string sentCheckSum = checkSum(sent, k);
    cout<<checkSum(sent, k)<<endl;      //printing checksum

	string recieveCheckSum = checkSum(recieve + sentCheckSum, k);

	if (count(recieveCheckSum.begin(), recieveCheckSum.end(), '0') == k){
		cout<<"0"<<endl;
	}
	else {
		cout<<"1"<<endl;
	}

	return 0;
}
