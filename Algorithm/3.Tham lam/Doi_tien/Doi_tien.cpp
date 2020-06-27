#include <iostream>
using namespace std;

int main (){
	int T; cin >> T;
	int a[10] = {1000,500,200,100,50,20,10,5,2,1};
	while (T--){
		int N; cin >> N;
		int soto = 0;
		for (int i = 0 ; i < 10 ; i++){
			soto = soto + N/a[i];
			N = N%a[i];
		}
		cout << soto << endl;
	}
	return 0;
}
