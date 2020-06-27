#include <iostream>
using namespace std;
const int p = 1000000007;

long long pow (long long N, long long K){
	if (K==1) return N;
	if (K%2!=0) return (N*pow(N,K-1))%p;
	else {
		long long r = pow(N,K/2);
		return (r*r)%p;
	}
}

int main (){
	int T;
	cin >> T;
	while (T--){
		int N,K;
		cin >> N >> K;
		cout << pow(N,K) << endl;
	}
	return 0;
}
