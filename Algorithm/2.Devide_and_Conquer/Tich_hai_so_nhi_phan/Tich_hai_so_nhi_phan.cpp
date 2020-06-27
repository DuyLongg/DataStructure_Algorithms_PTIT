#include <bits/stdc++.h>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		string S1,S2; cin >> S1 >> S2;
		reverse(S1.begin(),S1.end());
		reverse(S2.begin(),S2.end());
		long long sum1 = 0,sum2 = 0;
		for (int i = 0 ; i < S1.length() ; i++)
			if (S1[i] == '1') sum1 = sum1 + pow(2,i);
		for (int i = 0 ; i < S2.length() ; i++)
			if (S2[i] == '1') sum2 = sum2 + pow(2,i);
		cout << sum1 * sum2 << endl;
	}
	return 0;
}
