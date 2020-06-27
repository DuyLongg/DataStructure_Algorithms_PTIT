#include<bits/stdc++.h>
#define mod 123456789
using namespace std;

// So N co 2^(N-1) day

long long Mu (long long N){
	if (N==1) return 2;
	if (N%2) return (2 * (Mu(N-1)%mod)) % mod;
	else {
		long long r = Mu(N/2) % mod;// Tinh 2^(N/2)
		return (r*r) % mod ;
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		long long N; cin >> N;
		cout << Mu (N-1) << endl;// tinh 2^(N-1)
	}
	return 0;
}
