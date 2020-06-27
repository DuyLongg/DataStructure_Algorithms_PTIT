#include <bits/stdc++.h>
using namespace std;

int N,A[1005][1005];

int main (){
	cin >> N;
	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= N ; j++){
			cin >> A[i][j];
		}
	}
	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= N ; j++){
			if (A[i][j] == 1) cout << j << " ";
		} cout << endl;
	}
	return 0;
}
