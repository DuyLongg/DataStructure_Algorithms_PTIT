#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T,N,M,tmp,A[1000005],B[1000005];

int main (){
	cin >> T;
	while (T--){
		cin >> N >> M;
		memset (A,0,sizeof(A));
		memset (B,0,sizeof(B));
		for (int i = 1 ; i <= N ; i++) {
			cin >> tmp;
			A[tmp] = 1;
		}
		for (int i = 1 ; i <= M ; i++){
			cin >> tmp;
			B[tmp] = 1;
		}
		bool c2 = false;
		for (int i = 1 ; i <= 1000004 ; i++){
			if (A[i]==1 || B[i]==1) cout << i << " ";
		} cout << endl;
		for (int i = 1 ; i <= 1000004 ; i++){
			if (A[i]==1 && B[i]==1) {
				c2 = true;
				cout << i << " ";
			}
		} 
		if (c2) cout << endl;
	}
	return 0;
}
