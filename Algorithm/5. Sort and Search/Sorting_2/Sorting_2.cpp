#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T,N,X,A[100005];
pair <ll, ll> B[100005];

void Noi_bot (){
	bool check = false;
	for (int i = 1 ; i <= N ; i++){
		check = false;
		for (int j = 1 ; j <= N-i ; j++){
			if (B[j].first > B[j+1].first) {
				swap (B[j],B[j+1]);
				check = true;
			}
		}
		if (check == false) break;
	}
}

int main (){
	cin >> T;
	while (T--){
		cin >> N >> X;
		for (int i = 1 ; i <= N ; i++) {
			cin >> A[i];
			B[i] = make_pair(abs(X-A[i]), A[i]);
		}
		Noi_bot ();
		for (int i = 1 ; i <= N ; i++) cout << B[i].second << " ";
		cout << endl;
	}
	return 0;
}
