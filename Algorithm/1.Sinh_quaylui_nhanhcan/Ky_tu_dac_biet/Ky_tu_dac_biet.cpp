#include <iostream>
using namespace std;

string S;
long long N;
long long half_long [63];

int Gap (double tmp){
	for (int i = 0 ; i <= 62 ; i++) {
		if (tmp > half_long[i] && tmp <= half_long[i+1]) {
			return i+1;
		}
	}
}

int main (){
	cin >> S;
	cin >> N;// N la vt
	half_long[0] = S.size()/2;
	half_long[1] = S.size();
	for (int i = 2 ; i <= 62 ; i++) half_long[i] = half_long[i-1]*2;
	int so_lan_gap = Gap(N/2.0);
	while (N > S.size()){
		if(N%half_long[so_lan_gap]==1){
			N--; so_lan_gap--;
		}
		else {
			N = N-half_long[so_lan_gap]-1;
			if (N > S.size()) so_lan_gap = Gap(N/2.0);
		}
	}
	cout << S[N-1];
	return 0;
}
