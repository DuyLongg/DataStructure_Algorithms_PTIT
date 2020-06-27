#include <iostream>
using namespace std;

int dembit1 (int a[], int N){
	int dem = 0;
	for (int i = 0 ; i < N ; i++){
		if (a[i] == 1) dem++;
	}
	return dem;
}

void show (int a[], int N){
	for (int i = 0 ; i < N ; i++){
		cout << a[i];
	}
	cout << endl;
}

int main (){
	int T = 0;
	cin >> T;
	while (T--){
		int N,K;
		cin >> N >> K;
		int a[N] = {0};
		while (1){
			for (int i = N-1 ; i >= 0 ; i--){
				if (a[i] == 0){
					a[i] = 1;
					for (int j = i+1 ; j < N ; j++){
						a[j] = 0;
					}
					break;
				}
			}
			int dem1 = dembit1(a, N);
			if (dem1 == K){
				show(a,N);
			}
			if (dem1 == N) break;
		}
	}
	return 0;
}
