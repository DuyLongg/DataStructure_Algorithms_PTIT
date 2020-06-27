#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
// Made by DuyLongg
int T,N,S,A[202],L[40005];

int main (){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--){
		memset(L,0,sizeof(L));
		L[0] = 1;
		cin >> N >> S;
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		for (int i = 1 ; i <= N ; i++){
			for (int t = S ; t >= A[i] ; t--){
				if (L[t-A[i]]) L[t] = 1;
			}
		}
		if (L[S]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
