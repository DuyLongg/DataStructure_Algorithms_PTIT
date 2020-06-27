#include <bits/stdc++.h>
using namespace std;

int T,N,X,A[1005];

int main (){
	cin >> T;
	while (T--){
		cin >> N >> X;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		sort (A+1,A+N+1);
		int dem = 0;
		for (int i = 1 ; i <= N ; i++) {
			if (A[i] == X) dem++;
		}
		if (dem==0) cout << -1 << endl;
		else cout << dem << endl;
	}
	return 0;
}
