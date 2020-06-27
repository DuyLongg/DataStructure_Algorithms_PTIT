#include <iostream>
#include <algorithm>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		int S[N],F[N];
		pair <int,int> G[N];
		for (int i = 0 ; i < N ; i++) cin >> S[i];
		for (int i = 0 ; i < N ; i++) cin >> F[i];
		for (int i = 0 ; i < N ; i++) G[i] = make_pair(F[i],S[i]);
		sort (G,G+N);
		int so_cv = 1,j = 0;
		for (int i = 1 ; i < N ; i++){
			if (G[i].second >= G[j].first) {
				so_cv++; j = i;
			}
		}
		cout << so_cv << endl;
	}
	return 0;
}

