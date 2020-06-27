#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T,N,K,A[100005];

int main (){
	cin >> T;
	while (T--){
		cin >> N >> K;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		sort (A+1,A+N+1);
		ll dem = 0;
		for (int i = 1 ; i < N ; i++) {
			ll *iter = lower_bound (A+i, A+N+1, A[i]+K);
			dem = dem + iter - A - i - 1;
		}
		cout << dem << endl;
	}
	return 0;
}
