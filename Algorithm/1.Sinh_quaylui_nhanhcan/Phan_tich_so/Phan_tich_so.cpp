#include <iostream>
using namespace std;
int T,N,k=1;
int x[11];
bool test;
void next_division(){
	int i = k; 
	int j, R, S, D;
	while(i > 0 && x[i] == 1){
		i--;
	} 
	if(i > 0){
		x[i] = x[i] - 1;
		D = k - i + 1; R = D / x[i];
		S = D % x[i]; k = i;
		if(R > 0){
			for(int j = i + 1; j <= i + R; j++) x[j] = x[i];
			k = k + R;
		}
		if(S > 0){
			k = k + 1;
			x[k] = S;
		}	
	}
	else test = false;
}
void display(){
	cout << "(";
	for(int i = 1; i < k; i++){
		cout << x[i] << " ";
	}
	cout << x[k] << ") ";
}
int main(){
	cin >> T;
	while(T--){
		cin >> N;
		x[1] = N; k = 1;
		test = true;
		while(test){
			display();
			next_division();
		}
		cout << endl;
	}
	return 0;
}
