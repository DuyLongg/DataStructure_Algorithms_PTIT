#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T,N,M,A[100005],B[100005];

int main (){
	cin >> T;
	while (T--){
		cin >> N >> M;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		for (int i = 1 ; i <= M ; i++) cin >> B[i];
	//	sort (A+1,A+N+1);
	//	sort (B+1,B+M+1);
		int i,j;
		i = j = 1;
		while (i <= N && j <= M){
			if (A[i] < B[j]) {
				cout << A[i] << " ";
				i++;
			} else if (A[i] > B[j]){
				cout << B[j] << " ";
				j++;
			} else {
				cout << A[i] << " ";
				i++; j++;
			}
		}
		while (i <= N) {
			cout << A[i] << " ";
			i++;
		}
		while (j <= M){
			cout << B[j] << " ";
			j++;
		}
		cout << endl;
		////////////////////
		i = j = 1;
		while (i <= N && j <= M){
			if (A[i] < B[j]) i++;
			else if (A[i] > B[j]) j++;
			else {
				cout << A[i] << " ";
				i++; j++;
			}
		}
		cout << endl;
	}
	return 0;
}
