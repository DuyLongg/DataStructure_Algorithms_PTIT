#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;
ll Rever (ll N){
	ll N_dao = 0;
	while (N != 0){
		N_dao = N_dao*10 + N%10;
		N = N/10;
	}
	return N_dao;
}

ll Luy_thua (ll N, ll N_dao){
	if (N_dao == 0) return 1;
	long long x = Luy_thua (N,N_dao/2);
	if(N_dao%2==0) return x*x%mod;
	return N*(x*x%mod) % mod;
}

int main (){
	int T; cin >> T;
	while (T--){
		ll N; cin >> N;
		ll N_dao = Rever (N);
		cout << Luy_thua (N,N_dao) << endl; // pow (N,N_dao)
	}
	return 0;
}
