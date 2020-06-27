#include <bits/stdc++.h>
using namespace std;

int T,N,F[105]; // F[N] la do dai day tang lon nhat co phan tu A[N]
// F[1] = A[1];
pair <int,int> A[105];

int Solve (){
	memset (F,0,sizeof(F));
	F[1] = 1;
	int maxL = 1;
	for (int i = 2 ; i <= N ; i++){
		F[i] = 1;
		for (int j = 1 ; j < i ; j++){
			if (A[j].second < A[i].first) F[i] = max (F[i],F[j]+1);
		}
		if (F[i] > maxL) maxL = F[i];
	}
	return maxL;
}

bool condition (pair <int,int> &a, pair <int,int> &b) {
	return a.second < b.second;
}

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 1 ; i <= N ; i++)
			cin >> A[i].first >> A[i].second;
		sort (A+1,A+1+N,condition);
		cout << Solve() << endl;
	}
	return 0;
}
