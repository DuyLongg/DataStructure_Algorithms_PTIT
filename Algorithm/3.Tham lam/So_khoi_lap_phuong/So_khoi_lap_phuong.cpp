#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int So_digit(long long N){
	int dem = 0;
	while (N!=0){
		dem++;
		N=N/10;
	}
	return dem;
}

int main (){
	int T; cin >> T;
	while (T--){
		long long N; cin >> N;
		long long N_fake = N;
		vector <int> A;
		while (N_fake!=0) {
			A.push_back(N_fake%10);
			N_fake = N_fake/10;
		}
		reverse (A.begin(),A.end());
		long long tmp; int test = 0;
		for (long long i = cbrt(N) ; i >= 1 ; i--){
			tmp = i*i*i;
			int digit = So_digit (tmp);
			int tim_dc = 0;
			int j = A.size()-1; 
			while (tmp!=0){
				for (int n = j ; n >= 0 ; n--){
					if (A[n] == tmp%10) {
						j = n-1; 
						tim_dc++;
						break;
					} else if (n==0) tmp = 0;
				}
				tmp = tmp/10;
			}
			if (tim_dc == digit){
				cout << i*i*i << endl;
				test = 1;
				break;
			}
		}
		if (test == 0) cout << -1 << endl;
	}
	return 0;
}
