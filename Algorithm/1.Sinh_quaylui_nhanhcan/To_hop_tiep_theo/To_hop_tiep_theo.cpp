#include <iostream>
using namespace std;

int main (){
	int T = 0;
	cin >> T;
	while (T--){
		int N,K;
		cin >> N >> K;
		int a[K+1];
		int b[K+1];
		int bre = 0;
		for (int i = 1 ; i <= K ; i++){
			cin >> a[i];
			b[i] = a[i];
		}
		for (int i = K ; i > 0 ; i--){
			if (b[i] != N-K+i){
				b[i] = b[i] + 1;
				for (int j = i+1 ; j <= K ; j++){
					b[j] = b[i] + j - i;
				}
				break;
			}
			if (i == 1) {
				cout << K << endl;
				bre = 1;
			}
		}
		if (bre == 1) continue;
		int c[39] = {0};
		for (int i = 1 ; i <= K ; i++){
			c[b[i]] = b[i];
			c[a[i]] = a[i];
		}
		int dem = 0;
		for (int i = 1 ; i <= N ; i++){
			if (c[i] != 0) dem++;
		}
		cout << dem-K << endl;
	}
	return 0;
}
