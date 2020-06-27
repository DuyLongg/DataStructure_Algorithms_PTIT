#include <iostream>
#include <algorithm>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		int A[N];
		for (int i = 0 ; i < N ; i++) cin >> A[i];
		sort (A,A+N);
		long long so1 = 0, so2 = 0;
		for (int i = 0 ; i < N ; i = i+2) so1 = so1 * 10 + A[i];
		for (int i = 1 ; i < N ; i = i+2) so2 = so2 * 10 + A[i];
		cout << so1+so2 << endl;
	}
	return 0;
}
