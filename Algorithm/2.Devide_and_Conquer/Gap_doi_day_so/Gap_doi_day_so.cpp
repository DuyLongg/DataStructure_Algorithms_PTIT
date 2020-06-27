#include <iostream>
#include <math.h>
using namespace std;
long long K;
int Mu (long long i){
	int dem = 0;
	while (i!=1){
		i=i/2;
		dem++;
	}
	return dem;
}

void Try (){
	for (int x = 2 ; x <= 50 ; x++){
		long long i = K % (long long)pow (2,x);
		if (i!=0){
			cout << Mu(i)+1 << endl;
			break;
		}
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		int N;
		cin >> N >> K;
		if (K%2!=0) cout << 1 << endl;
		else {
			Try();
		}
	}
	return 0;
}
