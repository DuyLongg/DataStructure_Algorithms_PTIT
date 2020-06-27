#include <bits/stdc++.h>
using namespace std;

int T,N,A[100005];

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		for (int i = 1 ; i < N-1 ; i++){
			for (int j = i+1 ; j < N ; j++){
				if (A[j] > A[i]){
					for (int l = j+1 ; l <= N ; l++){
						if (A[l] < A[j]){
							cout << A[l] << " ";
							break;
						}
						if (l == N) cout << -1 << " ";
					}
					break;
				}
				if (j == N-1) cout << -1 << " ";
			}
		}
		cout << -1 << " " << -1 << endl;
	}
	return 0;
}
