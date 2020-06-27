#include <bits/stdc++.h>
#define ll long long
using namespace std;
// gioi han o de bai bi sai A[i] <= 10^5
long long T,dem,N,A[100005],B[100005];

int main (){
	cin >> T;
	while (T--){
		memset (B,0,sizeof(B));
		cin >> N;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		sort (A+1,A+N+1);
		dem = 0;
		for (int i = 1 ; i <= N ; i++) B[A[i]] = 1;
		for (int i = A[1] ; i <= A[N] ; i++) if (!B[i]) dem++;
		cout << dem << endl;
	}
	return 0;
}
