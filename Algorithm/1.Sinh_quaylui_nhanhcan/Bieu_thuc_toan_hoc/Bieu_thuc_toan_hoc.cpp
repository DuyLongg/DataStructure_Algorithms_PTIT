#include <bits/stdc++.h>
using namespace std;
bool In = false;
void Try_cal (int A[],int kq, int idx){
	if (idx == 5 && kq == 23) In = true;
	for (int i = 0 ; i < 3 ; i++){
		int next_idx = idx+1;
		if (next_idx > 5) break;
		if (i == 0) Try_cal (A,kq + A[idx],next_idx);
		else if (i == 1) Try_cal (A,kq - A[idx],next_idx);
		else Try_cal (A,kq * A[idx],next_idx);
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		int A[5];
		for (int i = 0 ; i < 5 ; i++) cin >> A[i];
		Try_cal (A,A[0],1);
		int GT = 119;
		while (GT--){
			next_permutation(A,A+5);
			Try_cal (A,A[0],1);
		}
		if (In == false) cout << "NO" << endl;
		else cout << "YES" << endl;
		In = false;
	}
	return 0;
}
