#include <bits/stdc++.h>
using namespace std;

int T,N,A[105],B[105],F1[105],F2[105]; 
// F1[i] la tong day con tang dai nhat ket thuc boi A[i] 
// F2[i] la tong day con giam dai nhat bat dau boi A[i]
// Tong day bi-tonic voi A[i] la trung tam = F1[1] + F2[i] - A[i]

void tang (){
	F1[1] = A[1];
	for (int i = 2 ; i <= N ; i++){
		F1[i] = A[i];
		for (int j = 1 ; j < i ; j++){
			if (A[j] < A[i]) F1[i] = max (F1[i],F1[j] + A[i]);
		}
	}
}

void giam (){
	F2[N] = A[N];
	for (int i = N-1 ; i >= 1 ; i--){
		F2[i] = A[i];
		for (int j = N ; j > i ; j--){
			if (A[j] < A[i]) F2[i] = max (F2[i],F2[j] + A[i]);
		}
	}
}

int Solve (){
	int maxL = F1[1] + F2[1] - A[1];
	for (int i = 2 ; i <= N ; i++){
		maxL = max (maxL, F1[i] + F2[i] - A[i]);
	}
	return maxL;
}

int main (){
	cin >> T;
	while (T--){
		memset (F1,0,sizeof(F1));
		memset (F2,0,sizeof(F2));
		cin >> N;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		tang(); giam();
		cout << Solve() << endl;
	}
	return 0;
}
