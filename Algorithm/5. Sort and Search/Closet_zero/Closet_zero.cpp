#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T,N,A[10005];

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		int min = INT_MAX;
		for (int i = 1 ; i < N ; i++){
			for (int j = i+1 ; j <= N ; j++){
				if (abs(A[i]+A[j]) < abs(min)) min = A[i] + A[j];
			}
		}
		cout << min << endl;
	}
	return 0;
}
