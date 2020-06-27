#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;
ll T,N,K; 

int main (){
	cin >> T;
	while (T--){
		cin >> N >> K;
		if (N<K) cout << 0 << endl;
		else {
			ll kq = 1;
			for (int i = 0 ; i <= K-1 ; i++){
				kq = (kq * (N-i)) % mod;
			}
			cout << kq << endl;
		}
	}
	return 0;
}
