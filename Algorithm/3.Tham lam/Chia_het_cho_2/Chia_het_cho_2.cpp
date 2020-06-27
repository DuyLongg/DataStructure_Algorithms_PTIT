#include <iostream>
#include <math.h>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		int dem = 0;
		if (N%2==0) {
			for (int i = 2 ; i <= sqrt(N) ; i++){
				if (N%i==0){
					if (i%2==0) dem++;
					if ((N/i)%2==0 && (N/i)!=i) dem++;
				}
			}
			cout << dem+1 << endl;

		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}
