#include <bits/stdc++.h>
using namespace std;

int T,N,A[100005];

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		for (int i = 1 ; i < N ; i++){
			for (int j = i+1 ; j <= N ; j++){
				if (A[j] > A[i]){
					cout << A[j] << " ";
					break;
				}
				if (j == N) cout << -1 << " ";
			}
		}
		cout << -1 << endl;
	}
	return 0;
}
