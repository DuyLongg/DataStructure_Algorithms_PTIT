#include <bits/stdc++.h>
using namespace std;

int T,N,K,dem,A[105];

int main (){
	cin >> T;
	while (T--){
		dem = 0;
		cin >> N >> K;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		sort (A+1,A+N+1);
		for (int i = 1 ; i <= N && A[i] <= K ; i++){
			for (int j = i+1 ; j <= N && A[j] <= K ; j++){
				if (A[i]+A[j] == K) dem++;
			}
		}
		cout << dem << endl;
	}
	return 0;
}
