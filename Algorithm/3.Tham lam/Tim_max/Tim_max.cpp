#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int main(){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		long long max = 0;
		long long A[N];
		for (int i = 0 ; i < N ; i++) cin >> A[i];
		sort(A,A+N);
		for (int i = 0 ; i < N ; i++){
			max = (max + A[i]*i) % MOD;
		} cout << max << endl;
	}
	return 0;
}
