#include <bits/stdc++.h>
using namespace std;

int Solve (string &A){
	int dem = 0,count = 0;
	if (A[0] == '[') count++;
	else count--;
	for (int i = 1 ; i < A.length() ; i++){
		if (A[i] == '[') count++;
		if (A[i] == ']') count--;
		if (i==1 && A[i] == '[' && A[i-1] == ']') {
			dem++; swap (A[i],A[i-1]);
		}
		if (A[i] == '[' && A[i-1] == ']' && count <= 0 && A[i-2] == ']'){
			dem++; swap (A[i],A[i-1]);
		}	
	}
	return dem;
}

int main (){
	int T; cin >> T;
	while (T--){
		string A; cin >> A;
		int kq = 0;
		while (true){
			int tmp = Solve(A);
			kq = kq + tmp;
			if (tmp==0) break;
		}
		cout << kq << endl;
	}
	return 0;
}
