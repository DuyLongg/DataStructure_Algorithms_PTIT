#include <iostream>
#include <algorithm>
using namespace std;

int Danh_dau(int G_second, int GH[]){
	for (int j = G_second ; j >= 1 ; j--){
		if (GH[j]==0){
			GH[j] = 1;
			return 1;
		}
	}
	return 0;
}

int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		int A[N][3]; int Max = 0;
		for (int i = 0 ; i < N ; i++){
			for (int j = 0 ; j < 3 ; j++) cin >> A[i][j];
			if (A[i][1] > Max) Max = A[i][1];
		}
		pair <int,int> G[N];
		for (int i = 0 ; i < N ; i++) G[i] = make_pair (A[i][2],A[i][1]);
		sort (G,G+N); int GH[Max+1] = {0}; long long sum_pro = 0,dem=0;
		for (int i = N-1 ; i >= 0 ; i--){
			if(Danh_dau(G[i].second,GH)) {
				sum_pro = sum_pro + G[i].first;
				dem++;
			}
		}
		cout << dem << " " << sum_pro << endl;
	}
	return 0;
}
