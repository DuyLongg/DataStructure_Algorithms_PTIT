#include <iostream>
#include <algorithm>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int N,K; cin >> N >> K;
		int A[N];
		for (int i = 0 ; i < N ; i++) cin >> A[i];
		sort (A,A+N);
		int min = (K <= N-K) ? K : N-K;
		int t1 = 0, t2 = 0;
		for (int i = 0 ; i < min ; i++)  t1 = t1 + A[i];
		for (int i = min ; i < N ; i++)  t2 = t2 + A[i];
		cout << t2-t1 << endl;
	}
	return 0;
}
