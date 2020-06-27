#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T,N,A[10005];
vector < pair <ll,ll> > B;

bool tmp (pair <ll,ll> &A , pair <ll,ll> &B){
	if (A.first < B.first) return true;
	if (A.first > B.first) return false;
	return A.second > B.second;
}

int main (){
	cin >> T;
	while (T--){
		B.clear();
		cin >> N;
		int tanso = 0;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		sort (A+1,A+N+1);
		for (int i = 1 ; i <= N ; i++){
			if (i == N) {
				if (A[i] == A[i-1]) B.push_back(make_pair (tanso+1,A[i]));
				else {
					B.push_back(make_pair (tanso,A[i-1]));
					B.push_back(make_pair (1,A[i]));
				}
			} else if (A[i] != A[i-1]){
				if (i != 1) B.push_back(make_pair(tanso,A[i-1]));
				tanso = 1;
			} else tanso++;
		}
		sort (B.begin(),B.end(),tmp);
		for (int i = B.size()-1 ; i >= 0 ; i--){
			while (B[i].first--) cout << B[i].second << " ";
		} cout << endl;
	}
	return 0;
}
